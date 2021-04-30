/*========================== begin_copyright_notice ============================

Copyright (C) 2017-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include "../include/BiF_Definitions.cl"
#include "../../Headers/spirv.h"
#include "../IMF/FP32/cosh_s_la.cl"

#if defined(cl_khr_fp64)
    #include "../IMF/FP64/cosh_d_la.cl"
#endif // defined(cl_khr_fp64)

float __builtin_spirv_OpenCL_cosh_f32( float x )
{
    float result;

    if(__FastRelaxedMath && (!__APIRS))
    {
        // Implemented as 0.5 * ( exp(x) + exp(-x) ).
        float pexp = __builtin_spirv_OpenCL_exp_f32(  x );
        float nexp = __builtin_spirv_OpenCL_exp_f32( -x );
        result = 0.5f * ( pexp + nexp );
    }
    else
    {
        result = __ocl_svml_coshf(x);
    }

    return result;
}

GENERATE_VECTOR_FUNCTIONS_1ARG_LOOP( __builtin_spirv_OpenCL_cosh, float, float, f32 )

#if defined(cl_khr_fp64)

INLINE double __builtin_spirv_OpenCL_cosh_f64( double x )
{
    return __ocl_svml_cosh(x);
}

GENERATE_VECTOR_FUNCTIONS_1ARG_LOOP( __builtin_spirv_OpenCL_cosh, double, double, f64 )

#endif // defined(cl_khr_fp64)

#if defined(cl_khr_fp16)

INLINE half __builtin_spirv_OpenCL_cosh_f16( half x )
{
    return __builtin_spirv_OpenCL_cosh_f32((float)x);
}

GENERATE_VECTOR_FUNCTIONS_1ARG_LOOP( __builtin_spirv_OpenCL_cosh, half, half, f16 )

#endif // defined(cl_khr_fp16)
