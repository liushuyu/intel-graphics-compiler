/*========================== begin_copyright_notice ============================

Copyright (c) 2000-2021 Intel Corporation

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom
the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.

============================= end_copyright_notice ===========================*/

#include "../imf.h"
#pragma OPENCL FP_CONTRACT OFF
typedef struct
{
    unsigned int AbsMask;
    unsigned int OneHalf;
    unsigned int sRsqrtMsk;
    unsigned int SmallNorm;
    unsigned int One;
    unsigned int HalfMask;
    unsigned int SQMask;
    unsigned int Two;
    unsigned int sqrt_coeff[2];
    unsigned int poly_coeff[5];
    unsigned int Pi2H;
    unsigned int Pi2L;
    unsigned int Zero;
    unsigned int SgnMask;
    unsigned int NanMask;
    unsigned int ep_coeff[3];
} __internal_sasin_la_data_t;
static __constant __internal_sasin_la_data_t __internal_sasin_la_data = {

    0x7fffffffu, 0x3f000000u, 0xfffff000u, 0x2f800000u, 0x3f800000u, 0xffffe000u, 0xfffff800u, 0x40000000u, {
                                                                                                             0xbdC00004u, 0x3e800001u}

    , {
       0x3d2EDC07u, 0x3CC32A6Bu, 0x3d3A9AB4u, 0x3d997C12u, 0x3e2AAAFFu}

    , 0x3fc90FDBu, 0xB33BBD2Eu, 0x00000000u, 0x80000000u, 0xffc00000u, {
                                                                        0x3dC4C6AEu, 0x3e2876B2u, 0x380561A3u}

};
static __constant int_float __sasin_la_c5 = { 0x3d2edc07u };
static __constant int_float __sasin_la_c4 = { 0x3cc32a6bu };
static __constant int_float __sasin_la_c3 = { 0x3d3a9ab4u };
static __constant int_float __sasin_la_c2 = { 0x3d997c12u };
static __constant int_float __sasin_la_c1 = { 0x3e2aaaffu };
static __constant int_float __sasin_la_c0 = { 0x3f800000u };
static __constant int_float __sasin_la_small_float = { 0x01800000u };

static __constant int_float __sasin_la_two = { 0x40000000u };

static __constant int_float __sasin_la_pi2h = { 0x3FC90FDBu };
static __constant int_float __sasin_la_pi2l = { 0xB33BBD2Eu };

__attribute__((always_inline))
inline int __internal_sasin_la_cout (float *pxin, float *pres)
{
    int nRet = 0;
    float xin = *pxin;
    int_float y, res;
    {
        int_float x, xa, RS, High, R0, Sh;
        unsigned sgn_x;
        float R, E, poly;

        x.f = xin;

        xa.w = x.w & 0x7fffffff;

        sgn_x = x.w ^ xa.w;

        y.f = __builtin_spirv_OpenCL_fma_f32_f32_f32 (-(0.5f), xa.f, 0.5f);

        R = xin * xin;
        R = __builtin_spirv_OpenCL_fmin_f32_f32 (R, y.f);

        RS.f = 1.0f / __builtin_spirv_OpenCL_sqrt_f32 (y.f + __sasin_la_small_float.f);

        Sh.f = (y.f * RS.f);
        Sh.f *= -2.0f;

        poly = __builtin_spirv_OpenCL_fma_f32_f32_f32 (__sasin_la_c5.f, R, __sasin_la_c4.f);
        poly = __builtin_spirv_OpenCL_fma_f32_f32_f32 (poly, R, __sasin_la_c3.f);
        poly = __builtin_spirv_OpenCL_fma_f32_f32_f32 (poly, R, __sasin_la_c2.f);
        poly = __builtin_spirv_OpenCL_fma_f32_f32_f32 (poly, R, __sasin_la_c1.f);
        poly = __builtin_spirv_OpenCL_fma_f32_f32_f32 (poly, R, __sasin_la_c0.f);

        R0.f = (xa.f <= 0.5f) ? xa.f : Sh.f;

        High.f = (xa.f <= 0.5f) ? 0 : __sasin_la_pi2h.f;

        res.f = (__builtin_spirv_OpenCL_fma_f32_f32_f32 (poly, R0.f, High.f));

        res.w |= sgn_x;

    }

    *pres = res.f;
    nRet = (y.f >= 0) ? 0 : 1;

    return nRet;
}

float __ocl_svml_asinf (float a)
{

    float va1;
    float vr1;
    unsigned int vm;

    float r;

    va1 = a;;

    __internal_sasin_la_cout (&va1, &vr1);
    r = vr1;;

    return r;

}
