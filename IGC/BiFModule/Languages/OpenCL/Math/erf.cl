/*========================== begin_copyright_notice ============================

Copyright (C) 2017-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include "../include/BiF_Definitions.cl"
#include "spirv.h"

INLINE float OVERLOADABLE erf( float x )
{
    return __builtin_spirv_OpenCL_erf_f32( x );
}

GENERATE_VECTOR_FUNCTIONS_1ARG( erf, float, float )

#if defined(cl_khr_fp64)

INLINE double OVERLOADABLE erf( double x )
{
    return __builtin_spirv_OpenCL_erf_f64( x );
}

GENERATE_VECTOR_FUNCTIONS_1ARG( erf, double, double )

#endif // defined(cl_khr_fp64)

#if defined(cl_khr_fp16)

INLINE half OVERLOADABLE erf( half x )
{
    return __builtin_spirv_OpenCL_erf_f16( x );
}

GENERATE_VECTOR_FUNCTIONS_1ARG( erf, half, half )

#endif // defined(cl_khr_fp16)
