/*========================== begin_copyright_notice ============================

Copyright (C) 2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#ifndef IGCLLVM_IR_BASICBLOCK_H
#define IGCLLVM_IR_BASICBLOCK_H

#include <llvm/Config/llvm-config.h>
#include <llvm/Transforms/Utils/BasicBlockUtils.h>
#include "llvm/IR/BasicBlock.h"

namespace IGCLLVM {
inline llvm::filter_iterator<llvm::BasicBlock::const_iterator,
  std::function<bool(const llvm::Instruction &)>>::difference_type
sizeWithoutDebug(const llvm::BasicBlock *BB) {
  return std::distance(BB->instructionsWithoutDebug().begin(),
                       BB->instructionsWithoutDebug().end());
}

inline void insertIntoBB(llvm::BasicBlock *BB, llvm::Instruction *I) {
#if LLVM_VERSION_MAJOR < 16
  BB->getInstList().push_back(I);
#else
  I->insertInto(BB, BB->end());
#endif
}

inline void eraseLastFromBB(llvm::BasicBlock *BB) {
#if LLVM_VERSION_MAJOR < 16
  BB->getInstList().pop_back();
#else
  BB->back().eraseFromParent();
#endif
}

inline void eraseOneFromBB(llvm::BasicBlock *BB, llvm::Instruction *I) {
#if LLVM_VERSION_MAJOR < 16
  BB->getInstList().erase(I);
#else
  auto IT = llvm::BasicBlock::iterator{I};
  auto ITNext = std::next(IT);
  BB->erase(IT, ITNext);
#endif
}

inline void spliceBB(llvm::BasicBlock *ContextBB, llvm::BasicBlock::iterator ToIt, llvm::BasicBlock *FromBB, llvm::BasicBlock::iterator FromBeginIt, llvm::BasicBlock::iterator FromEndIt) {
#if LLVM_VERSION_MAJOR < 16
  ContextBB->getInstList().splice(ToIt, FromBB->getInstList(), FromBeginIt, FromEndIt);
#else
  ContextBB->splice(ToIt, FromBB, FromBeginIt, FromEndIt);
#endif
}

inline void ReplaceInstWithValue([[maybe_unused]] llvm::BasicBlock *BB, llvm::BasicBlock::iterator &BI, llvm::Value *V) {
#if LLVM_VERSION_MAJOR < 16
  llvm::ReplaceInstWithValue(BB->getInstList(), BI, V);
#else
  llvm::ReplaceInstWithValue(BI, V);
#endif
}
} // namespace IGCLLVM

#endif
