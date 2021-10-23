/*========================== begin_copyright_notice ============================

Copyright (C) 2017-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

/*
 * !!! DO NOT EDIT THIS FILE !!!
 *
 * This file was automagically crafted by GED's model parser.
 */

#include <cstddef>
#include "ged_enumerations_internal.h"

#ifndef GED_ACCESS_MODE_HIDDEN
const char* AccessModeEnumeration[3] =
{
    "Align1", // 0
    "Align16", // 1
    NULL // 2
}; // AccessModeEnumeration[]
#endif // GED_ACCESS_MODE_HIDDEN

#ifndef GED_ACC_WR_CTRL_HIDDEN
const char* AccWrCtrlEnumeration[3] =
{
    "", // 0
    "AccWrEn", // 1
    NULL // 2
}; // AccWrCtrlEnumeration[]
#endif // GED_ACC_WR_CTRL_HIDDEN

#ifndef GED_ADDR_MODE_HIDDEN
const char* AddrModeEnumeration[3] =
{
    "Direct", // 0
    "Indirect", // 1
    NULL // 2
}; // AddrModeEnumeration[]
#endif // GED_ADDR_MODE_HIDDEN

#ifndef GED_ARCH_REG_HIDDEN
const char* ArchRegEnumeration[16] =
{
    "null", // 0
    "a0", // 1
    "acc", // 2
    "f", // 3
    "ce", // 4
    "msg", // 5
    "sp", // 6
    "sr0", // 7
    "cr0", // 8
    "n0", // 9
    "ip", // 10
    "tdr", // 11
    "tm0", // 12
    "fc", // 13
    "dbg0", // 14
    NULL // 15
}; // ArchRegEnumeration[]
#endif // GED_ARCH_REG_HIDDEN

#ifndef GED_ATOMIC_OPERATION_TYPE_HIDDEN
const char* AtomicOperationTypeEnumeration[16] =
{
    "AOP_AND", // 0
    "AOP_OR", // 1
    "AOP_XOR", // 2
    "AOP_MOV", // 3
    "AOP_INC", // 4
    "AOP_DEC", // 5
    "AOP_ADD", // 6
    "AOP_SUB", // 7
    "AOP_REVSUB", // 8
    "AOP_IMAX", // 9
    "AOP_IMIN", // 10
    "AOP_UMAX", // 11
    "AOP_UMIN", // 12
    "AOP_CMPWR", // 13
    "AOP_PREDEC", // 14
    NULL // 15
}; // AtomicOperationTypeEnumeration[]
#endif // GED_ATOMIC_OPERATION_TYPE_HIDDEN

#ifndef GED_BLOCK_SIZE_HIDDEN
const char* BlockSizeEnumeration[6] =
{
    "OW1L", // 0
    "OW1H", // 1
    "OW2", // 2
    "OW4", // 3
    "OW8", // 4
    NULL // 5
}; // BlockSizeEnumeration[]
#endif // GED_BLOCK_SIZE_HIDDEN

#ifndef GED_BRANCH_CTRL_HIDDEN
const char* BranchCtrlEnumeration[3] =
{
    "", // 0
    "Branch", // 1
    NULL // 2
}; // BranchCtrlEnumeration[]
#endif // GED_BRANCH_CTRL_HIDDEN

#ifndef GED_CHANNEL_MASK_HIDDEN
const char* ChannelMaskEnumeration[6] =
{
    "R", // 0
    "", // 1
    "B", // 2
    "G", // 3
    "A", // 4
    NULL // 5
}; // ChannelMaskEnumeration[]
#endif // GED_CHANNEL_MASK_HIDDEN

#ifndef GED_CHANNEL_MODE_HIDDEN
const char* ChannelModeEnumeration[3] =
{
    "Oword", // 0
    "Dword", // 1
    NULL // 2
}; // ChannelModeEnumeration[]
#endif // GED_CHANNEL_MODE_HIDDEN

#ifndef GED_CHANNEL_OFFSET_HIDDEN
const char* ChannelOffsetEnumeration[9] =
{
    "M0", // 0
    "M4", // 1
    "M8", // 2
    "M12", // 3
    "M16", // 4
    "M20", // 5
    "M24", // 6
    "M28", // 7
    NULL // 8
}; // ChannelOffsetEnumeration[]
#endif // GED_CHANNEL_OFFSET_HIDDEN

#ifndef GED_COND_MODIFIER_HIDDEN
const char* CondModifierEnumeration[10] =
{
    "", // 0
    "z", // 1
    "nz", // 2
    "g", // 3
    "ge", // 4
    "l", // 5
    "le", // 6
    "o", // 7
    "u", // 8
    NULL // 9
}; // CondModifierEnumeration[]
#endif // GED_COND_MODIFIER_HIDDEN

#ifndef GED_DATA_TYPE_HIDDEN
const char* DataTypeEnumeration[20] =
{
    "ud", // 0
    "d", // 1
    "uw", // 2
    "w", // 3
    "ub", // 4
    "b", // 5
    "df", // 6
    "f", // 7
    "uq", // 8
    "q", // 9
    "hf", // 10
    "uv", // 11
    "vf", // 12
    "v", // 13
    "nf", // 14
    "bf", // 15
    "qf", // 16
    "bf8", // 17
    "tf32", // 18
    NULL // 19
}; // DataTypeEnumeration[]
#endif // GED_DATA_TYPE_HIDDEN

#ifndef GED_DEBUG_CTRL_HIDDEN
const char* DebugCtrlEnumeration[3] =
{
    "", // 0
    "Breakpoint", // 1
    NULL // 2
}; // DebugCtrlEnumeration[]
#endif // GED_DEBUG_CTRL_HIDDEN

#ifndef GED_DEP_CTRL_HIDDEN
const char* DepCtrlEnumeration[5] =
{
    "", // 0
    "NoDDClr", // 1
    "NoDDChk", // 2
    "NoDDClr, NoDDChk", // 3
    NULL // 4
}; // DepCtrlEnumeration[]
#endif // GED_DEP_CTRL_HIDDEN

#ifndef GED_DP_ADDR_SIZE_HIDDEN
const char* DpAddrSizeEnumeration[4] =
{
    "A16", // 0
    "A32", // 1
    "A64", // 2
    NULL // 3
}; // DpAddrSizeEnumeration[]
#endif // GED_DP_ADDR_SIZE_HIDDEN

#ifndef GED_DP_ADDR_TYPE_HIDDEN
const char* DpAddrTypeEnumeration[5] =
{
    "FLAT", // 0
    "BSS", // 1
    "SS", // 2
    "BTI", // 3
    NULL // 4
}; // DpAddrTypeEnumeration[]
#endif // GED_DP_ADDR_TYPE_HIDDEN

#ifndef GED_DP_DATA_SIZE_HIDDEN
const char* DpDataSizeEnumeration[8] =
{
    "D8", // 0
    "D16", // 1
    "D32", // 2
    "D64", // 3
    "D8U32", // 4
    "D16U32", // 5
    "D16BF32", // 6
    NULL // 7
}; // DpDataSizeEnumeration[]
#endif // GED_DP_DATA_SIZE_HIDDEN

#ifndef GED_DP_FENCE_SCOPE_HIDDEN
const char* DpFenceScopeEnumeration[8] =
{
    "Threadgroup", // 0
    "Local", // 1
    "Tile", // 2
    "GPU", // 3
    "AllGPU", // 4
    "System_Release", // 5
    "System_Acquire", // 6
    NULL // 7
}; // DpFenceScopeEnumeration[]
#endif // GED_DP_FENCE_SCOPE_HIDDEN

#ifndef GED_DP_FLUSH_TYPE_HIDDEN
const char* DpFlushTypeEnumeration[7] =
{
    "Evict", // 0
    "Invalidate", // 1
    "Discard", // 2
    "Clean", // 3
    "DGT_L3OnlyFlush", // 4
    "None", // 5
    NULL // 6
}; // DpFlushTypeEnumeration[]
#endif // GED_DP_FLUSH_TYPE_HIDDEN

#ifndef GED_DP_OPCODE_HIDDEN
const char* DpOpcodeEnumeration[28] =
{
    "LOAD", // 0
    "LOAD_CMASK", // 1
    "STORE", // 2
    "STORE_CMASK", // 3
    "ATOMIC_INC", // 4
    "ATOMIC_DEC", // 5
    "ATOMIC_LOAD", // 6
    "ATOMIC_STORE", // 7
    "ATOMIC_ADD", // 8
    "ATOMIC_SUB", // 9
    "ATOMIC_MIN", // 10
    "ATOMIC_MAX", // 11
    "ATOMIC_UMIN", // 12
    "ATOMIC_UMAX", // 13
    "ATOMIC_CMPXCHG", // 14
    "ATOMIC_FADD", // 15
    "ATOMIC_FSUB", // 16
    "ATOMIC_FMIN", // 17
    "ATOMIC_FMAX", // 18
    "ATOMIC_FCMPXCHG", // 19
    "ATOMIC_AND", // 20
    "ATOMIC_OR", // 21
    "ATOMIC_XOR", // 22
    "STORE_UNCOMPRESSED", // 23
    "FENCE", // 24
    "LOAD_BLOCK2D", // 25
    "STORE_BLOCK2D", // 26
    NULL // 27
}; // DpOpcodeEnumeration[]
#endif // GED_DP_OPCODE_HIDDEN

#ifndef GED_DP_TRANSPOSE_HIDDEN
const char* DpTransposeEnumeration[3] =
{
    "SIMT", // 0
    "SIMD", // 1
    NULL // 2
}; // DpTransposeEnumeration[]
#endif // GED_DP_TRANSPOSE_HIDDEN

#ifndef GED_DP_VECT_SIZE_HIDDEN
const char* DpVectSizeEnumeration[9] =
{
    "V1", // 0
    "V2", // 1
    "V3", // 2
    "V4", // 3
    "V8", // 4
    "V16", // 5
    "V32", // 6
    "V64", // 7
    NULL // 8
}; // DpVectSizeEnumeration[]
#endif // GED_DP_VECT_SIZE_HIDDEN

#ifndef GED_DST_CHAN_EN_HIDDEN
const char* DstChanEnEnumeration[17] =
{
    "", // 0
    "x", // 1
    "y", // 2
    "xy", // 3
    "z", // 4
    "xz", // 5
    "yz", // 6
    "xyz", // 7
    "w", // 8
    "xw", // 9
    "yw", // 10
    "xyw", // 11
    "zw", // 12
    "xzw", // 13
    "yzw", // 14
    "xyzw", // 15
    NULL // 16
}; // DstChanEnEnumeration[]
#endif // GED_DST_CHAN_EN_HIDDEN

#ifndef GED_EOT_HIDDEN
const char* EOTEnumeration[3] =
{
    "", // 0
    "EOT", // 1
    NULL // 2
}; // EOTEnumeration[]
#endif // GED_EOT_HIDDEN

#ifndef GED_EVICT_HINT_HIDDEN
const char* EvictHintEnumeration[8] =
{
    "None", // 0
    "Src0", // 1
    "Acc0", // 2
    "Src0Acc0", // 3
    "Src1", // 4
    "Src0Src1", // 5
    "Acc0Src1", // 6
    NULL // 7
}; // EvictHintEnumeration[]
#endif // GED_EVICT_HINT_HIDDEN

#ifndef GED_EXEC_MASK_OFFSET_CTRL_HIDDEN
const char* ExecMaskOffsetCtrlEnumeration[15] =
{
    "N1", // 0
    "N2", // 1
    "N3", // 2
    "N4", // 3
    "N5", // 4
    "N6", // 5
    "N7", // 6
    "N8", // 7
    "Q1", // 8
    "Q2", // 9
    "Q3", // 10
    "Q4", // 11
    "H1", // 12
    "H2", // 13
    NULL // 14
}; // ExecMaskOffsetCtrlEnumeration[]
#endif // GED_EXEC_MASK_OFFSET_CTRL_HIDDEN

#ifndef GED_EXECUTION_DATA_TYPE_HIDDEN
const char* ExecutionDataTypeEnumeration[3] =
{
    "Integer", // 0
    "Float", // 1
    NULL // 2
}; // ExecutionDataTypeEnumeration[]
#endif // GED_EXECUTION_DATA_TYPE_HIDDEN

#ifndef GED_FUSION_CTRL_HIDDEN
const char* FusionCtrlEnumeration[3] =
{
    "", // 0
    "Serialized", // 1
    NULL // 2
}; // FusionCtrlEnumeration[]
#endif // GED_FUSION_CTRL_HIDDEN

#ifndef GED_HEADER_PRESENT_HIDDEN
const char* HeaderPresentEnumeration[3] =
{
    "no", // 0
    "yes", // 1
    NULL // 2
}; // HeaderPresentEnumeration[]
#endif // GED_HEADER_PRESENT_HIDDEN

#ifndef GED_MASK_CTRL_HIDDEN
const char* MaskCtrlEnumeration[3] =
{
    "", // 0
    "NoMask", // 1
    NULL // 2
}; // MaskCtrlEnumeration[]
#endif // GED_MASK_CTRL_HIDDEN

#ifndef GED_MATH_FC_HIDDEN
const char* MathFCEnumeration[15] =
{
    "INV", // 0
    "LOG", // 1
    "EXP", // 2
    "SQRT", // 3
    "RSQ", // 4
    "SIN", // 5
    "COS", // 6
    "FDIV", // 7
    "POW", // 8
    "INT DIV BOTH", // 9
    "INT DIV QUOTIENT", // 10
    "INT DIV REMAINDER", // 11
    "INVM", // 12
    "RSQRTM", // 13
    NULL // 14
}; // MathFCEnumeration[]
#endif // GED_MATH_FC_HIDDEN

#ifndef GED_MATH_MACRO_EXT_HIDDEN
const char* MathMacroExtEnumeration[10] =
{
    "mme0", // 0
    "mme1", // 1
    "mme2", // 2
    "mme3", // 3
    "mme4", // 4
    "mme5", // 5
    "mme6", // 6
    "mme7", // 7
    "nomme", // 8
    NULL // 9
}; // MathMacroExtEnumeration[]
#endif // GED_MATH_MACRO_EXT_HIDDEN

#ifndef GED_MESSAGE_TYPE_HIDDEN
const char* MessageTypeEnumeration[78] =
{
    "MSD0R_HWB", // 0
    "MSD0W_HWB", // 1
    "MT0R_OWB", // 2
    "MT0R_OWAB", // 3
    "MT0R_OWDB", // 4
    "MT0R_DWS", // 5
    "MT0R_BS", // 6
    "MT0_MEMFENCE", // 7
    "MT0W_OWB", // 8
    "MT0W_OWDB", // 9
    "MT0W_DWS", // 10
    "MT0W_BS", // 11
    "MT1R_T", // 12
    "MT1R_US", // 13
    "MT1A_UI", // 14
    "MT1A_UI4x2", // 15
    "MT1R_MB", // 16
    "MT1R_TS", // 17
    "MT1A_TA", // 18
    "MT1A_TA4x2", // 19
    "MT1W_US", // 20
    "MT1W_MB", // 21
    "MT1A_TC", // 22
    "MT1A_TC4x2", // 23
    "MT1W_TS", // 24
    "MT1R_A64_SB", // 25
    "MT1R_A64_US", // 26
    "MT1A_A64_UI", // 27
    "MT1A_A64_UI4x2", // 28
    "MT1R_A64_B", // 29
    "MT1W_A64_B", // 30
    "MT1W_A64_US", // 31
    "MT1W_A64_SB", // 32
    "MT2R_US", // 33
    "MT2R_A64_SB", // 34
    "MT2R_A64_US", // 35
    "MT2R_BS", // 36
    "MT2W_US", // 37
    "MT2W_A64_US", // 38
    "MT2W_A64_SB", // 39
    "MT2W_BS", // 40
    "MT_CC_OWB", // 41
    "MT_CC_OWUB", // 42
    "MT_CC_OWDB", // 43
    "MT_CC_DWS", // 44
    "MT_SC_OWUB", // 45
    "MT_SC_MB", // 46
    "MT_RSI", // 47
    "MT_RTW", // 48
    "MT_RTR", // 49
    "MT1A_UHI", // 50
    "MT1A_TAH", // 51
    "MT1A_TCH", // 52
    "MT1A_A64_UHI", // 53
    "MT1A_UF", // 54
    "MT1A_UHF", // 55
    "MT1A_A64_UF", // 56
    "MT1A_A64_UHF", // 57
    "MT_US_CCS_OP", // 58
    "MT_US_UCW", // 59
    "MT_TS_CCS_OP", // 60
    "MT_TS_UCW", // 61
    "MT_A64_CCS_PG_OP", // 62
    "MT_A64_US_CCS_OP", // 63
    "MT_A64_US_UCW", // 64
    "MT_BTD_SPAWN", // 65
    "MTR_MB", // 66
    "MTRR_TS", // 67
    "MTRA_TA", // 68
    "MT_MEMFENCE", // 69
    "MTW_MB", // 70
    "MTRW_TS", // 71
    "MT0R_US", // 72
    "MT0A_UI", // 73
    "MT0W_US", // 74
    "MT1A_UF4x2", // 75
    "MT1A_A64_UF4x2", // 76
    NULL // 77
}; // MessageTypeEnumeration[]
#endif // GED_MESSAGE_TYPE_HIDDEN

#ifndef GED_NO_SRC_DEP_SET_HIDDEN
const char* NoSrcDepSetEnumeration[3] =
{
    "", // 0
    "NoSrcDepSet", // 1
    NULL // 2
}; // NoSrcDepSetEnumeration[]
#endif // GED_NO_SRC_DEP_SET_HIDDEN

#ifndef GED_OPCODE_HIDDEN
const char* OpcodeEnumeration[82] =
{
    "illegal", // 0
    "mov", // 1
    "sel", // 2
    "movi", // 3
    "not", // 4
    "and", // 5
    "or", // 6
    "xor", // 7
    "shr", // 8
    "shl", // 9
    "smov", // 10
    "asr", // 11
    "cmp", // 12
    "cmpn", // 13
    "csel", // 14
    "bfrev", // 15
    "bfe", // 16
    "bfi1", // 17
    "bfi2", // 18
    "jmpi", // 19
    "brd", // 20
    "if", // 21
    "brc", // 22
    "else", // 23
    "endif", // 24
    "while", // 25
    "break", // 26
    "cont", // 27
    "halt", // 28
    "calla", // 29
    "call", // 30
    "ret", // 31
    "goto", // 32
    "join", // 33
    "wait", // 34
    "send", // 35
    "sendc", // 36
    "sends", // 37
    "sendsc", // 38
    "math", // 39
    "add", // 40
    "mul", // 41
    "avg", // 42
    "frc", // 43
    "rndu", // 44
    "rndd", // 45
    "rnde", // 46
    "rndz", // 47
    "mac", // 48
    "mach", // 49
    "lzd", // 50
    "fbh", // 51
    "fbl", // 52
    "cbit", // 53
    "addc", // 54
    "subb", // 55
    "sad2", // 56
    "sada2", // 57
    "dp4", // 58
    "dph", // 59
    "dp3", // 60
    "dp2", // 61
    "line", // 62
    "pln", // 63
    "mad", // 64
    "lrp", // 65
    "madm", // 66
    "nop", // 67
    "ror", // 68
    "rol", // 69
    "dp4a", // 70
    "sync", // 71
    "add3", // 72
    "dpas", // 73
    "dpasw", // 74
    "bfn", // 75
    "macl", // 76
    "srnd", // 77
    "f32to16", // 78
    "f16to32", // 79
    "dim", // 80
    NULL // 81
}; // OpcodeEnumeration[]
#endif // GED_OPCODE_HIDDEN

#ifndef GED_PRECISION_HIDDEN
const char* PrecisionEnumeration[13] =
{
    "u8", // 0
    "u4", // 1
    "u2", // 2
    "u1", // 3
    "s8", // 4
    "s4", // 5
    "s2", // 6
    "s1", // 7
    "f16", // 8
    "bf16", // 9
    "bf8", // 10
    "tf32", // 11
    NULL // 12
}; // PrecisionEnumeration[]
#endif // GED_PRECISION_HIDDEN

#ifndef GED_PRED_CTRL_HIDDEN
const char* PredCtrlEnumeration[21] =
{
    "", // 0
    "", // 1
    "anyv", // 2
    "allv", // 3
    "any2h", // 4
    "all2h", // 5
    "any4h", // 6
    "all4h", // 7
    "any8h", // 8
    "all8h", // 9
    "any16h", // 10
    "all16h", // 11
    "any32h", // 12
    "all32h", // 13
    "x", // 14
    "y", // 15
    "z", // 16
    "w", // 17
    "any", // 18
    "all", // 19
    NULL // 20
}; // PredCtrlEnumeration[]
#endif // GED_PRED_CTRL_HIDDEN

#ifndef GED_PRED_INV_HIDDEN
const char* PredInvEnumeration[3] =
{
    "+", // 0
    "-", // 1
    NULL // 2
}; // PredInvEnumeration[]
#endif // GED_PRED_INV_HIDDEN

#ifndef GED_REG_FILE_HIDDEN
const char* RegFileEnumeration[4] =
{
    "ARF", // 0
    "GRF", // 1
    "IMM", // 2
    NULL // 3
}; // RegFileEnumeration[]
#endif // GED_REG_FILE_HIDDEN

#ifndef GED_REP_CTRL_HIDDEN
const char* RepCtrlEnumeration[3] =
{
    "", // 0
    "", // 1
    NULL // 2
}; // RepCtrlEnumeration[]
#endif // GED_REP_CTRL_HIDDEN

#ifndef GED_RETURN_DATA_CONTROL_HIDDEN
const char* ReturnDataControlEnumeration[3] =
{
    "", // 0
    "", // 1
    NULL // 2
}; // ReturnDataControlEnumeration[]
#endif // GED_RETURN_DATA_CONTROL_HIDDEN

#ifndef GED_SATURATE_HIDDEN
const char* SaturateEnumeration[3] =
{
    "", // 0
    "sat", // 1
    NULL // 2
}; // SaturateEnumeration[]
#endif // GED_SATURATE_HIDDEN

#ifndef GED_SFID_HIDDEN
const char* SFIDEnumeration[22] =
{
    "NULL", // 0
    "SAMPLER", // 1
    "GATEWAY", // 2
    "DP_DC2", // 3
    "DP_RC", // 4
    "URB", // 5
    "SPAWNER", // 6
    "VME", // 7
    "DP_DCRO", // 8
    "DP_DC0", // 9
    "PI", // 10
    "DP_DC1", // 11
    "CRE", // 12
    "UGML", // 13
    "BTD", // 14
    "RTA", // 15
    "TGM", // 16
    "SLM", // 17
    "UGM", // 18
    "DP_SAMPLER", // 19
    "DP_CC", // 20
    NULL // 21
}; // SFIDEnumeration[]
#endif // GED_SFID_HIDDEN

#ifndef GED_SIMDMODE_HIDDEN
const char* SIMDModeEnumeration[4] =
{
    "SIMD4x2", // 0
    "SIMD16", // 1
    "SIMD8", // 2
    NULL // 3
}; // SIMDModeEnumeration[]
#endif // GED_SIMDMODE_HIDDEN

#ifndef GED_SLOT_GROUP_HIDDEN
const char* SlotGroupEnumeration[4] =
{
    "SIMD4x2", // 0
    "low_8", // 1
    "high_8", // 2
    NULL // 3
}; // SlotGroupEnumeration[]
#endif // GED_SLOT_GROUP_HIDDEN

#ifndef GED_SRC_MOD_HIDDEN
const char* SrcModEnumeration[5] =
{
    "", // 0
    "(abs)", // 1
    "-", // 2
    "-(abs)", // 3
    NULL // 4
}; // SrcModEnumeration[]
#endif // GED_SRC_MOD_HIDDEN

#ifndef GED_STORE_HINT_HIDDEN
const char* StoreHintEnumeration[6] =
{
    "None", // 0
    "Src0", // 1
    "Acc0", // 2
    "Dst", // 3
    "Src1", // 4
    NULL // 5
}; // StoreHintEnumeration[]
#endif // GED_STORE_HINT_HIDDEN

#ifndef GED_SUB_BYTE_PRECISION_HIDDEN
const char* SubBytePrecisionEnumeration[8] =
{
    "None", // 0
    "s4", // 1
    "s2", // 2
    "s1", // 3
    "u4", // 4
    "u2", // 5
    "u1", // 6
    NULL // 7
}; // SubBytePrecisionEnumeration[]
#endif // GED_SUB_BYTE_PRECISION_HIDDEN

#ifndef GED_SUB_FUNC_ID_HIDDEN
const char* SubFuncIDEnumeration[8] =
{
    "GetTimeStamp", // 0
    "BarrierMsg", // 1
    "OpenGateway", // 2
    "CloseGateway", // 3
    "ForwardMsg", // 4
    "UpdateGateState", // 5
    "MMIOReadWrite", // 6
    NULL // 7
}; // SubFuncIDEnumeration[]
#endif // GED_SUB_FUNC_ID_HIDDEN

#ifndef GED_SWIZZLE_HIDDEN
const char* SwizzleEnumeration[5] =
{
    "x", // 0
    "y", // 1
    "z", // 2
    "w", // 3
    NULL // 4
}; // SwizzleEnumeration[]
#endif // GED_SWIZZLE_HIDDEN

#ifndef GED_SYNC_FC_HIDDEN
const char* SyncFCEnumeration[8] =
{
    "nop", // 0
    "grfsb", // 1
    "allrd", // 2
    "allwr", // 3
    "bar", // 4
    "host", // 5
    "fence", // 6
    NULL // 7
}; // SyncFCEnumeration[]
#endif // GED_SYNC_FC_HIDDEN

#ifndef GED_THREAD_CTRL_HIDDEN
const char* ThreadCtrlEnumeration[5] =
{
    "", // 0
    "Atomic", // 1
    "NoPreempt", // 2
    "Switch", // 3
    NULL // 4
}; // ThreadCtrlEnumeration[]
#endif // GED_THREAD_CTRL_HIDDEN
