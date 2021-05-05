/*========================== begin_copyright_notice ============================

Copyright (c) 2013-2021 Intel Corporation

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

#ifndef CODE_GEN_PUBLIC_ENUMS_H_
#define CODE_GEN_PUBLIC_ENUMS_H_

#include "../IGC/common/EmUtils.h"

namespace IGC
{
    enum HullShaderDispatchModes : signed int
    {
        SINGLE_PATCH_DISPATCH_MODE,
        DUAL_PATCH_DISPATCH_MODE,
        EIGHT_PATCH_DISPATCH_MODE,
    };

    enum DomainShaderDispatchModes : signed int
    {
        DS_SIMD4x2_DISPATCH_MODE = 0x0,
        DS_SINGLE_PATCH_DISPATCH_MODE = 0x1,
        DS_DUAL_PATCH_DISPATCH_MODE = 0x2
    };

    enum PixelShaderPhaseType
    {
        PSPHASE_COARSE,
        PSPHASE_PIXEL,
        PSPHASE_SAMPLE,
        PSPHASE_LEGACY,
    };

    enum e_interpolation : signed int
    {
        EINTERPOLATION_UNDEFINED,
        EINTERPOLATION_CONSTANT,
        EINTERPOLATION_LINEAR,
        EINTERPOLATION_LINEARCENTROID,
        EINTERPOLATION_LINEARNOPERSPECTIVE,
        EINTERPOLATION_LINEARNOPERSPECTIVECENTROID,
        EINTERPOLATION_LINEARSAMPLE,
        EINTERPOLATION_LINEARNOPERSPECTIVESAMPLE,
        EINTERPOLATION_VERTEX,
        NUMBER_EINTERPOLATION
    };

    enum ShaderOutputType : signed int
    {
        SHADER_OUTPUT_TYPE_DEFAULT = 0,
        SHADER_OUTPUT_TYPE_POSITION,
        SHADER_OUTPUT_TYPE_CLIPDISTANCE_LO,
        SHADER_OUTPUT_TYPE_CLIPDISTANCE_HI,
        SHADER_OUTPUT_TYPE_DEPTHOUT,
        SHADER_OUTPUT_TYPE_STENCIL,
        SHADER_OUTPUT_TYPE_VIEWPORT_ARRAY_INDEX,
        SHADER_OUTPUT_TYPE_RENDER_TARGET_ARRAY_INDEX,
        SHADER_OUTPUT_TYPE_POINTWIDTH,
        SHADER_OUTPUT_TYPE_OMASK,
        SHADER_OUTPUT_TYPE_FINAL_LINE_DENSITY_TESSFACTOR,
        SHADER_OUTPUT_TYPE_FINAL_LINE_DETAIL_TESSFACTOR,
        SHADER_OUTPUT_TYPE_FINAL_QUAD_U_EQ_0_EDGE_TESSFACTOR,
        SHADER_OUTPUT_TYPE_FINAL_QUAD_U_EQ_1_EDGE_TESSFACTOR,
        SHADER_OUTPUT_TYPE_FINAL_QUAD_U_INSIDE_TESSFACTOR,
        SHADER_OUTPUT_TYPE_FINAL_QUAD_V_EQ_0_EDGE_TESSFACTOR,
        SHADER_OUTPUT_TYPE_FINAL_QUAD_V_EQ_1_EDGE_TESSFACTOR,
        SHADER_OUTPUT_TYPE_FINAL_QUAD_V_INSIDE_TESSFACTOR,
        SHADER_OUTPUT_TYPE_FINAL_TRI_U_EQ_0_EDGE_TESSFACTOR,
        SHADER_OUTPUT_TYPE_FINAL_TRI_V_EQ_0_EDGE_TESSFACTOR,
        SHADER_OUTPUT_TYPE_FINAL_TRI_W_EQ_0_EDGE_TESSFACTOR,
        SHADER_OUTPUT_TYPE_FINAL_TRI_INSIDE_TESSFACTOR,
        SHADER_OUTPUT_TYPE_COARSE_PIXEL_SIZE,
        SHADER_OUTPUT_TYPE_UNKNOWN
    };

    enum BufferType : short
    {
        CONSTANT_BUFFER = 0,
        UAV,
        RESOURCE,
        SLM,
        POINTER,
        BINDLESS,
        BINDLESS_CONSTANT_BUFFER,
        BINDLESS_TEXTURE,
        SAMPLER,
        BINDLESS_SAMPLER,
        RENDER_TARGET,
        STATELESS,
        STATELESS_READONLY,
        STATELESS_A32,
        BUFFER_TYPE_UNKNOWN = 31
    };

    enum BufferAccessType : short
    {
        ACCESS_READ = 0,
        ACCESS_WRITE,
        ACCESS_READWRITE,
        ACCESS_SAMPLE,
        BUFFER_ACCESS_TYPE_UNKNOWN = 15,
    };

    enum ADDRESS_SPACE : unsigned int
    {
        ADDRESS_SPACE_PRIVATE = 0,
        ADDRESS_SPACE_GLOBAL = 1,
        ADDRESS_SPACE_CONSTANT = 2,
        ADDRESS_SPACE_LOCAL = 3,
        ADDRESS_SPACE_GENERIC = 4,
        ADDRESS_SPACE_A32 = 5,

        ADDRESS_SPACE_GLOBAL_OR_PRIVATE = 20,

        ADDRESS_SPACE_NUM_ADDRESSES
    };

    enum AtomicOp : unsigned int
    {
        EATOMIC_IADD,
        EATOMIC_SUB,
        EATOMIC_INC,
        EATOMIC_DEC,
        EATOMIC_MIN,
        EATOMIC_MAX,
        EATOMIC_XCHG,
        EATOMIC_CMPXCHG,
        EATOMIC_AND,
        EATOMIC_OR,
        EATOMIC_XOR,
        EATOMIC_IMIN,
        EATOMIC_IMAX,
        EATOMIC_UMAX,
        EATOMIC_UMIN,
        EATOMIC_PREDEC,
        EATOMIC_FMIN,
        EATOMIC_FMAX,
        EATOMIC_FCMPWR,
        //64 bit
        EATOMIC_IADD64,
        EATOMIC_SUB64,
        EATOMIC_INC64,
        EATOMIC_DEC64,
        EATOMIC_MIN64,
        EATOMIC_MAX64,
        EATOMIC_XCHG64,
        EATOMIC_CMPXCHG64,
        EATOMIC_AND64,
        EATOMIC_OR64,
        EATOMIC_XOR64,
        EATOMIC_IMIN64,
        EATOMIC_IMAX64,
        EATOMIC_UMAX64,
        EATOMIC_UMIN64,
        EATOMIC_PREDEC64,
        EATOMIC_UNDEF
    };

    enum class WaveOps : unsigned int
    {
        SUM,
        PROD,
        UMIN,
        UMAX,
        IMIN,
        IMAX,
        OR,
        XOR,
        AND,
        FSUM,
        FPROD,
        FMIN,
        FMAX,
        UNDEF
    };

    enum GroupOpType
    {
        GroupOperationScan,
        GroupOperationReduce,
        GroupOperationClusteredReduce
    };

    enum SGVUsage
    {
        POSITION_X,
        POSITION_Y,
        POSITION_Z,
        POSITION_W,
        VFACE,
        PRIMITIVEID,
        GS_INSTANCEID,
        POINT_WIDTH,
        INPUT_COVERAGE_MASK,
        SAMPLEINDEX,
        CLIP_DISTANCE,
        THREAD_ID_X,
        THREAD_ID_Y,
        THREAD_ID_Z,
        THREAD_GROUP_ID_X,
        THREAD_GROUP_ID_Y,
        THREAD_GROUP_ID_Z,
        THREAD_ID_IN_GROUP_X,
        THREAD_ID_IN_GROUP_Y,
        THREAD_ID_IN_GROUP_Z,
        OUTPUT_CONTROL_POINT_ID,
        DOMAIN_POINT_ID_X,
        DOMAIN_POINT_ID_Y,
        DOMAIN_POINT_ID_Z,
        VERTEX_ID,
        REQUESTED_COARSE_SIZE_X,
        REQUESTED_COARSE_SIZE_Y,
        ACTUAL_COARSE_SIZE_X,
        ACTUAL_COARSE_SIZE_Y,
        CLIP_DISTANCE_X,
        CLIP_DISTANCE_Y,
        CLIP_DISTANCE_Z,
        CLIP_DISTANCE_W,
        POSITION_X_OFFSET,
        POSITION_Y_OFFSET,
        RENDER_TARGET_ARRAY_INDEX,
        MSAA_RATE,
        XP0,
        XP1,
        XP2,
        NUM_SGV,
    };

    enum Float_DenormMode
    {
        FLOAT_DENORM_FLUSH_TO_ZERO = 0,
        FLOAT_DENORM_RETAIN,
    };

    enum ERoundingMode
    {
        ROUND_TO_NEAREST_EVEN,
        ROUND_TO_POSITIVE,
        ROUND_TO_NEGATIVE,
        ROUND_TO_ZERO,

        ROUND_TO_ANY   // dont care
    };


}

#endif //CODE_GEN_PUBLIC_ENUMS_H_
