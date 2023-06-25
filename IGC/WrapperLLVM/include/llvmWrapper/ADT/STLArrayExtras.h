/*========================== begin_copyright_notice ============================

Copyright (C) 2020-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#ifndef IGCLLVM_ADT_STLARRAYEXTRAS_H
#define IGCLLVM_ADT_STLARRAYEXTRAS_H

#include "llvm/Config/llvm-config.h"
#if LLVM_VERSION_MAJOR > 15
#include <iterator>
#else
#include "llvm/ADT/STLArrayExtras.h"
#endif

namespace IGCLLVM
{
#if LLVM_VERSION_MAJOR <= 15
    using llvm::array_lengthof;
#else
    template <typename T, size_t N>
    constexpr size_t array_lengthof(const T (&A)[N]) { return N; }
#endif
}

#endif // IGCLLVM_ADT_STLARRAYEXTRAS_H
