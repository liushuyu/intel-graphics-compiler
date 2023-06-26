/*========================== begin_copyright_notice ============================

Copyright (C) 2018-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#ifndef IGCLLVM_IR_FUNCTION_H
#define IGCLLVM_IR_FUNCTION_H

#include "llvm/IR/Function.h"
#include <iterator>
#include <llvm/IR/Value.h>

#include "Probe/Assertion.h"

namespace IGCLLVM {

inline llvm::Argument *getArg(const llvm::Function &F, unsigned ArgNo) {
  IGC_ASSERT(F.arg_size() > ArgNo);
  llvm::Argument *Arg = nullptr;

#if LLVM_VERSION_MAJOR < 10
  // similar to lvm::Function::getArg implementation
  auto ArgIt = F.arg_begin();
  std::advance(ArgIt, ArgNo);
  Arg = const_cast<llvm::Argument *>(&*ArgIt);
#else
  Arg = F.getArg(ArgNo);
#endif

  return Arg;
}

inline void addRetAttr(llvm::Function *F, llvm::Attribute::AttrKind Kind) {
#if LLVM_VERSION_MAJOR < 14
  F->addAttribute(llvm::AttributeList::ReturnIndex, Kind);
#else
  F->addRetAttr(Kind);
#endif
}

inline bool onlyWritesMemory(llvm::Function *F) {
#if LLVM_VERSION_MAJOR < 14
  return F->doesNotReadMemory();
#else
  return F->onlyWritesMemory();
#endif
}

inline void spliceBasicBlockList(llvm::Function *F, llvm::Function::iterator ToIt, llvm::Function *FromF) {
#if LLVM_VERSION_MAJOR < 16
  F->getBasicBlockList().splice(ToIt, FromF->getBasicBlockList());
#else
  F->splice(ToIt, FromF);
#endif
}

inline void spliceBasicBlockList(llvm::Function *F, llvm::Function::iterator ToIt, llvm::Function *FromF, llvm::Function::iterator FromIt) {
#if LLVM_VERSION_MAJOR < 16
  F->getBasicBlockList().splice(ToIt, FromF->getBasicBlockList(), FromIt);
#else
  F->splice(ToIt, FromF, FromIt);
#endif
}

inline void spliceBasicBlockList(llvm::Function *F, llvm::Function::iterator ToIt, llvm::Function *FromF, llvm::Function::iterator FromBeginIt, llvm::Function::iterator FromEndIt) {
#if LLVM_VERSION_MAJOR < 16
  F->getBasicBlockList().splice(ToIt, FromF->getBasicBlockList(), FromBeginIt, FromEndIt);
#else
  F->splice(ToIt, FromF, FromBeginIt, FromEndIt);
#endif
}

inline void appendBasicBlockList(llvm::Function *F, llvm::BasicBlock *BB) {
#if LLVM_VERSION_MAJOR < 16
  F->getBasicBlockList().push_back(BB);
#else
  BB->insertInto(F, nullptr);
#endif
}

inline llvm::Function::iterator insertBasicBlockList(llvm::Function *F, llvm::Function::iterator Position, llvm::BasicBlock *BB) {
#if LLVM_VERSION_MAJOR < 16
  return F->getBasicBlockList().insert(Position, BB);
#else
  return F->insert(Position, BB);
#endif
}

inline auto getFunctionReverseIteratorBegin(llvm::Function *F) {
#if LLVM_VERSION_MAJOR < 16
  return F->getBasicBlockList().rbegin();
#else
  return std::make_reverse_iterator(F->begin());
#endif
}

inline auto getFunctionReverseIteratorEnd(llvm::Function *F) {
#if LLVM_VERSION_MAJOR < 16
  return F->getBasicBlockList().rend();
#else
  return std::make_reverse_iterator(F->end());
#endif
}

} // namespace IGCLLVM

#endif
