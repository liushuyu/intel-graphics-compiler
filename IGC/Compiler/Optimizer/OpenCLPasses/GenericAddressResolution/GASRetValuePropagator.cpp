/*========================== begin_copyright_notice ============================

Copyright (C) 2017-2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include "GASRetValuePropagator.h"

#include "Compiler/CISACodeGen/ShaderCodeGen.hpp"
#include "Compiler/InitializePasses.h"
#include "LLVM3DBuilder/MetadataBuilder.h"

#include "common/LLVMWarningsPush.hpp"
#include "llvm/Analysis/CallGraph.h"
#include "llvm/ADT/PostOrderIterator.h"
#include "common/LLVMWarningsPop.hpp"
#include "llvmWrapper/IR/Function.h"

#define PASS_FLAG "igc-gas-ret-value-propagator"
#define PASS_DESC "Resolve generic pointer return value"
#define PASS_CFG_ONLY false
#define PASS_ANALYSIS false
IGC_INITIALIZE_PASS_BEGIN(GASRetValuePropagator, PASS_FLAG, PASS_DESC, PASS_CFG_ONLY, PASS_ANALYSIS)
IGC_INITIALIZE_PASS_DEPENDENCY(MetaDataUtilsWrapper)
IGC_INITIALIZE_PASS_DEPENDENCY(CodeGenContextWrapper)
IGC_INITIALIZE_PASS_DEPENDENCY(CallGraphWrapperPass)
IGC_INITIALIZE_PASS_DEPENDENCY(LoopInfoWrapperPass)
IGC_INITIALIZE_PASS_END(GASRetValuePropagator, PASS_FLAG, PASS_DESC, PASS_CFG_ONLY, PASS_ANALYSIS)

ModulePass* IGC::createGASRetValuePropagatorPass() { return new GASRetValuePropagator(); }

char GASRetValuePropagator::ID = 0;

bool GASRetValuePropagator::runOnModule(Module& M) {
    bool changed = false;
    m_module = &M;
    m_mdUtils = getAnalysis<MetaDataUtilsWrapper>().getMetaDataUtils();
    m_ctx = getAnalysis<CodeGenContextWrapper>().getCodeGenContext();

    CallGraph& CG = getAnalysis<CallGraphWrapperPass>().getCallGraph();
    std::vector<Function*> candidates = findCandidates(CG);

    for (auto* F : candidates)
    {
        LoopInfo& LI = getAnalysis<LoopInfoWrapperPass>(*F).getLoopInfo();
        GASPropagator ThePropagator(F->getContext(), &LI);
        m_Propagator = &ThePropagator;

        if (propagateReturnValue(F))
        {
            changed = true;
        }
    }

    return changed;
}

bool GASRetValuePropagator::propagateReturnValue(Function*& F) {
    PointerType* nonGASPtr = getRetValueNonGASType(F);

    if (!nonGASPtr) return false;

    Function* newFunc = cloneFunctionWithModifiedRetType(F, nonGASPtr);

    updateAllUsesWithNewFunction(F, newFunc);

    IGC_ASSERT(nullptr != F);
    IGC_ASSERT_MESSAGE(F->use_empty(), "All function uses should have been transfered to new function");
    F->eraseFromParent();
    F = newFunc;
    return true;
}

std::vector<Function*> GASRetValuePropagator::findCandidates(CallGraph& CG) {
    std::vector<Function*> candidates;

    auto skip = [](Function* F)
    {
        // Skip functions with variable number of arguments, e.g. printf.
        if (F->isVarArg())
            return true;

        // Only non-extern functions within the module are optimized
        if (F->hasFnAttribute("referenced-indirectly") || F->isDeclaration()
            || F->isIntrinsic() || F->user_empty())
            return true;

        return false;
    };

    auto isGenericPtrTy = [](Type* T)
    {
        return T->isPointerTy() && T->getPointerAddressSpace() == ADDRESS_SPACE_GENERIC;
    };

    // Find the candidates, which are functions returning generic pointer args.
    // Functions will be updated later in down-top ordering (starting from most nested function).
    for (auto I : post_order(&CG))
    {
        auto F = I->getFunction();
        if (F == nullptr)
            continue;
        if (skip(F))
            continue;
        if (!isGenericPtrTy(F->getReturnType()))
            continue;

        candidates.push_back(F);
    }

    return candidates;
}

std::vector<ReturnInst*> GASRetValuePropagator::getAllRetInstructions(Function& F)
{
    std::vector<ReturnInst*> retInstructions;
    for (auto& BB : F)
    {
        if (auto retInst = dyn_cast<ReturnInst>(BB.getTerminator()))
        {
            retInstructions.push_back(retInst);
        }
    }
    return retInstructions;
}

PointerType* GASRetValuePropagator::getRetValueNonGASType(Function* F)
{
    std::vector<ReturnInst*> retInstructions = getAllRetInstructions(*F);

    std::optional<unsigned> originAddrSpace = std::nullopt;
    for (auto retInst : retInstructions)
    {
        Value* retValue = retInst->getReturnValue();

        if (isa<ConstantPointerNull>(retValue))
            continue;

        if (!isa<AddrSpaceCastInst>(retValue))
            return nullptr;

        auto I = cast<AddrSpaceCastInst>(retValue);
        IGC_ASSERT(I->getDestAddressSpace() == ADDRESS_SPACE_GENERIC);

        unsigned AS = I->getSrcAddressSpace();
        if (originAddrSpace && originAddrSpace.value() != AS)
            return nullptr;

        originAddrSpace.emplace(AS);
    }

    return originAddrSpace ?
        PointerType::get(IGCLLVM::getNonOpaquePtrEltTy(F->getReturnType()), originAddrSpace.value()) :
        nullptr;
}

Function* GASRetValuePropagator::createNewFunctionDecl(Function* oldFunc, Type* newRetTy)
{
    Module* M = oldFunc->getParent();
    ArrayRef<Type*> params = oldFunc->getFunctionType()->params();
    FunctionType* newFTy = FunctionType::get(newRetTy, params, oldFunc->isVarArg());

    Function* newFunc = Function::Create(newFTy, oldFunc->getLinkage());
    newFunc->copyAttributesFrom(oldFunc);
    newFunc->setSubprogram(oldFunc->getSubprogram());
    M->getFunctionList().insert(oldFunc->getIterator(), newFunc);
    newFunc->takeName(oldFunc);
    return newFunc;
}

void GASRetValuePropagator::transferFunctionBody(Function* oldFunc, Function* newFunc)
{
    newFunc->stealArgumentListFrom(*oldFunc);
    IGCLLVM::spliceBasicBlockList(newFunc, newFunc->begin(), oldFunc);
}

void GASRetValuePropagator::updateFunctionRetInstruction(Function* F)
{
    std::vector<ReturnInst*> retInstructions = getAllRetInstructions(*F);

    for (auto retInst : retInstructions)
    {
        Value* retValue = retInst->getReturnValue();

        if (isa<ConstantPointerNull>(retValue))
        {
            retInst->setOperand(0, ConstantPointerNull::get(cast<PointerType>(F->getReturnType())));
            continue;
        }

        IGC_ASSERT(isa<AddrSpaceCastInst>(retValue));

        auto ASC = cast<AddrSpaceCastInst>(retValue);
        IGC_ASSERT(ASC->getDestAddressSpace() == ADDRESS_SPACE_GENERIC);

        retInst->setOperand(0, ASC->getPointerOperand());

        if (ASC->use_empty()) ASC->eraseFromParent();
    }
}

void GASRetValuePropagator::updateAllUsesWithNewFunction(Function* oldFunc, Function* newFunc)
{
    IGC_ASSERT(!oldFunc->use_empty());

    // Keep track of old calls and addrspacecast to be deleted later
    std::vector<CallInst*> callsToDelete;

    for (auto U : oldFunc->users())
    {
        CallInst* cInst = dyn_cast<CallInst>(U);
        if (!cInst)
        {
            IGC_ASSERT_MESSAGE(0, "Unknown function usage");
            return;
        }

        // Prepare args for new call
        std::vector<Value*> callArgs;
        for (unsigned I = 0, E = IGCLLVM::getNumArgOperands(cInst); I != E; ++I) {
            callArgs.push_back(cInst->getArgOperand(I));
        }

        // Create new call and insert it before old one
        CallInst* newCall = CallInst::Create(newFunc, callArgs, "", cInst);

        newCall->setCallingConv(newFunc->getCallingConv());
        newCall->setAttributes(cInst->getAttributes());
        newCall->setDebugLoc(cInst->getDebugLoc());

        IGC_ASSERT(oldFunc->getType()->isPointerTy() &&
            newFunc->getReturnType()->isPointerTy());

        auto* oldRetTy = dyn_cast<PointerType>(oldFunc->getReturnType());
        auto* newRetTy = dyn_cast<PointerType>(newFunc->getReturnType());

        IGC_ASSERT(
            oldRetTy->getAddressSpace() == ADDRESS_SPACE_GENERIC &&
            newRetTy->getAddressSpace() != ADDRESS_SPACE_GENERIC);

        auto ASC = CastInst::Create(Instruction::AddrSpaceCast, newCall, oldFunc->getReturnType(), "", cInst);

        cInst->replaceAllUsesWith(ASC);
        callsToDelete.push_back(cInst);

        m_Propagator->propagate(newCall);
    }

    // Delete old calls
    for (auto call : callsToDelete)
    {
        call->eraseFromParent();
    }
}

Function* GASRetValuePropagator::cloneFunctionWithModifiedRetType(Function* F, PointerType* newRetTy)
{
    Function* newFunc = createNewFunctionDecl(F, newRetTy);
    transferFunctionBody(F, newFunc);
    updateFunctionRetInstruction(newFunc);
    updateMetadata(F, newFunc);
    return newFunc;
}

void GASRetValuePropagator::updateMetadata(Function* oldFunc, Function* newFunc) {
    MetadataBuilder mbuilder(m_module);
    auto& FuncMD = m_ctx->getModuleMetaData()->FuncMD;

    auto oldFuncIter = m_mdUtils->findFunctionsInfoItem(oldFunc);
    m_mdUtils->setFunctionsInfoItem(newFunc, oldFuncIter->second);
    m_mdUtils->eraseFunctionsInfoItem(oldFuncIter);
    mbuilder.UpdateShadingRate(oldFunc, newFunc);
    auto loc = FuncMD.find(oldFunc);
    if (loc != FuncMD.end())
    {
        auto funcInfo = loc->second;
        FuncMD.erase(oldFunc);
        FuncMD[newFunc] = funcInfo;
    }

    m_mdUtils->save(m_module->getContext());
}
