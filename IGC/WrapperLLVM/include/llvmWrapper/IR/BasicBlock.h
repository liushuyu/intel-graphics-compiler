/*========================== begin_copyright_notice ============================

Copyright (C) 2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#ifndef IGCLLVM_IR_BASICBLOCK_H
#define IGCLLVM_IR_BASICBLOCK_H

#include <llvm/Config/llvm-config.h>
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
} // namespace IGCLLVM

#endif
