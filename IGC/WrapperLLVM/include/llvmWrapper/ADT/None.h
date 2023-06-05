/*========================== begin_copyright_notice ============================

Copyright (C) 2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#ifndef IGCLLVM_ADT_NONE_H
#define IGCLLVM_ADT_NONE_H

namespace IGCLLVM {
#if LLVM_VERSION_MAJOR < 16
#include "llvm/ADT/None.h"
const llvm::NoneType None = IGCLLVM::None;
#else
#include <optional>
// copied from llvm/ADT/None.h (version 16.0.0)
inline constexpr std::nullopt_t None = std::nullopt;
#endif
} // namespace IGCLLVM

#endif // IGCLLVM_ADT_NONE_H
