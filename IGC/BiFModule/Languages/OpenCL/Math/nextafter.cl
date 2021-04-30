/*========================== begin_copyright_notice ============================

Copyright (C) 2017-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include "../include/BiF_Definitions.cl"
#include "spirv.h"

float OVERLOADABLE nextafter( float x, float y )
{
    return __builtin_spirv_OpenCL_nextafter_f32_f32( x, y );
}

GENERATE_VECTOR_FUNCTIONS_2ARGS( nextafter, float, float )

#if defined(cl_khr_fp64)

double OVERLOADABLE nextafter( double x, double y )
{
    return __builtin_spirv_OpenCL_nextafter_f64_f64( x, y );
}

GENERATE_VECTOR_FUNCTIONS_2ARGS( nextafter, double, double )

#endif // defined(cl_khr_fp64)

#if defined(cl_khr_fp16)

half OVERLOADABLE nextafter( half x, half y )
{
    return __builtin_spirv_OpenCL_nextafter_f16_f16( x, y );
}

GENERATE_VECTOR_FUNCTIONS_2ARGS( nextafter, half, half )

#endif // defined(cl_khr_fp16)
