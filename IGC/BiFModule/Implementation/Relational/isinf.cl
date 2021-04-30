/*========================== begin_copyright_notice ============================

Copyright (C) 2017-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include "../include/BiF_Definitions.cl"
#include "spirv.h"

INLINE int OVERLOADABLE __intel_relaxed_isinf( float x )
{
    int result = SPIRV_BUILTIN(IsInf, _f32, )(x);
    // This could check for -cl-finite-math-only, not -cl-fast-relaxed-math.
    return __FastRelaxedMath ? 0 : result;
}

#if defined(cl_khr_fp64)
INLINE int OVERLOADABLE __intel_relaxed_isinf( double x )
{
    int result = SPIRV_BUILTIN(IsInf, _f64, )(x);
    // This could check for -cl-finite-math-only, not -cl-fast-relaxed-math.
    return __FastRelaxedMath ? 0 : result;
}
#endif // defined(cl_khr_fp64)

INLINE int OVERLOADABLE __intel_relaxed_isinf( half x )
{
    int result = SPIRV_BUILTIN(IsInf, _f16, )(x);
    // This could check for -cl-finite-math-only, not -cl-fast-relaxed-math.
    return __FastRelaxedMath ? 0 : result;
}

