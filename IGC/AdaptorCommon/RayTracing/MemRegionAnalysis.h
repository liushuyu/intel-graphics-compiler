/*========================== begin_copyright_notice ============================

Copyright (C) 2020-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#pragma once

#include "common/MDFrameWork.h"
#include "common/LLVMWarningsPush.hpp"
#include "llvmWrapper/ADT/Optional.h"
#include "common/LLVMWarningsPop.hpp"

namespace llvm {
    class Value;
    class DataLayout;
}

namespace IGC {

enum class RTMemRegion : uint32_t
{
    RTAsyncStack,
    RTSyncStack,
    SWStack,
    SWHotZone,
    RTGlobals,
    LocalArgs,
};

IGCLLVM::Optional<RTMemRegion>
getRTRegionByAddrspace(const llvm::Value* V, const ModuleMetaData& MMD);

IGCLLVM::Optional<RTMemRegion> getRegionOffset(
    const llvm::Value* Ptr,
    const llvm::DataLayout* DL = nullptr,
    uint64_t* Offset = nullptr,
    uint64_t* dereferenceable_value = nullptr);

IGCLLVM::Optional<RTMemRegion>
getRTRegion(const llvm::Value* Ptr, const ModuleMetaData &MMD);

} // namespace IGC

