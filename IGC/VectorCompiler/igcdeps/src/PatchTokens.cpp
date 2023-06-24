/*========================== begin_copyright_notice ============================

Copyright (C) 2021-2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include "vc/Driver/Driver.h"
#include "vc/Support/ShaderDump.h"
#include "vc/Support/Status.h"
#include "vc/igcdeps/cmc.h"

#include "AdaptorOCL/OCL/sp/sp_g8.h"
#include "lldWrapper/Common/Driver.h"

#include <llvm/Support/Debug.h>
#include <llvm/Support/FileUtilities.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/BinaryFormat/ELF.h>

using namespace vc;

struct DebugInfo {
  llvm::StringRef KernelName;
  llvm::StringRef DebugData;
};

// Implementation of CGen8CMProgram.
CGen8CMProgram::CGen8CMProgram(PLATFORM platform, const WA_TABLE &WATable,
                               llvm::ArrayRef<char> SPIRV,
                               IGCLLVM::Optional<llvm::StringRef> Opts)
    : CGen8OpenCLProgramBase(platform, m_ContextProvider, WATable),
      m_programInfo(new IGC::SOpenCLProgramInfo), m_spirv(SPIRV), m_opts(Opts) {
}

TmpFilesStorage
CGen8CMProgram::extractRawDebugInfo(llvm::raw_ostream &ErrStream) {
  std::vector<DebugInfo> DebugInfoData;
  std::transform(
      m_kernels.begin(), m_kernels.end(), std::back_inserter(DebugInfoData),
      [](const auto &Kernel) {
        llvm::StringRef KernelName = Kernel->m_kernelInfo.m_kernelName;
        const auto &KO = Kernel->getProgramOutput();
        if (!KO.m_debugData)
          return DebugInfo{KernelName, llvm::StringRef{}};
        const auto *RawData =
            reinterpret_cast<const char *>(KO.m_debugData);
        return DebugInfo{KernelName,
                         llvm::StringRef{RawData, KO.m_debugDataSize}};
      });
  IGC_ASSERT(DebugInfoData.size() == m_kernels.size());

  TmpFilesStorage Result;
  for (const auto &DebugInfo : DebugInfoData) {
    llvm::SmallString<128> TmpPath;
    int FD = -1;
    auto EC = llvm::sys::fs::createTemporaryFile("ze", "elf", FD, TmpPath);
    if (EC) {
      ErrStream << "could not create temporary file: " << EC.message() << "\n";
      return {};
    }
    addElfKernelMapping(TmpPath.c_str(), DebugInfo.KernelName.str());

    auto Out = std::make_unique<llvm::ToolOutputFile>(TmpPath, FD);
    Out->os() << DebugInfo.DebugData;
    Out->os().flush();

    auto Emplaced = Result.emplace(TmpPath.str(), std::move(Out));
    IGC_ASSERT_MESSAGE(Emplaced.second,
                       "could not create unique temporary storage");
  }
  IGC_ASSERT(DebugInfoData.size() == Result.size());
  return Result;
}

std::unique_ptr<llvm::MemoryBuffer> CGen8CMProgram::buildZeDebugInfo() {
  llvm::raw_string_ostream ErrStream{m_ErrorLog};
  auto TmpFiles = extractRawDebugInfo(ErrStream);
  if (TmpFiles.empty()) {
    ErrStream << "could not initialize linking of the debug information\n";
    return {};
  }

  llvm::SmallString<128> OutputPath;
  auto Errc =
      llvm::sys::fs::createTemporaryFile("final_dbginfo", "elf", OutputPath);
  if (Errc) {
    ErrStream << "could not create output file for the linked debug info: "
              << Errc.message() << "\n";
    return {};
  }

  std::vector<const char *> LldArgs;
  LldArgs.push_back("lld");
  std::transform(TmpFiles.begin(), TmpFiles.end(), std::back_inserter(LldArgs),
                 [](const auto &TmpFile) { return TmpFile.first.c_str(); });
  LldArgs.push_back("--relocatable");
  LldArgs.push_back("-o");
  LldArgs.push_back(OutputPath.c_str());

  if (IGC_IS_FLAG_ENABLED(VCEnableExtraDebugLogging)) {
    for (const auto *Arg : LldArgs)
      llvm::errs() << " " << Arg;
    llvm::errs() << "\n";
  }

  // Currently, DummyOutput/OutStream are not used outside of debugging purposes
  // (we don't have facilities to emit extra logs from binary building routines)
  std::string DummyOutput;
  llvm::raw_string_ostream OutStream(DummyOutput);
  constexpr bool CanExitEarly = false;
  if (!IGCLLD::elf::link(LldArgs, CanExitEarly, OutStream, ErrStream)) {
    ErrStream << "could not link debug infomation file\n";
    return {};
  }
  llvm::FileRemover Remover{OutputPath};

  if (IGC_IS_FLAG_ENABLED(VCEnableExtraDebugLogging)) {
    if (!OutStream.str().empty())
      llvm::errs() << "lld stdout:\n" << DummyOutput << "\n";
    else
      llvm::errs() << "lld has nothing on stdout (ok)\n";
  }

  auto Res = llvm::MemoryBuffer::getFile(OutputPath);
  if (!Res) {
    ErrStream << "could not read linked debug information file\n";
    return {};
  }
  if (Res.get()->getBufferSize() == 0) {
    ErrStream << "file with the linked debug information is empty\n";
    return {};
  }

  return std::move(Res.get());
}

llvm::Error CGen8CMProgram::GetError() const {
  IGC_ASSERT(HasErrors());
  return llvm::make_error<vc::OutputBinaryCreationError>(m_ErrorLog);
}

void CGen8CMProgram::CreateKernelBinaries(CompileOptions& Opts) {
  CreateProgramScopePatchStream(*m_programInfo);
  for (const auto &kernel : m_kernels) {
    // Create the kernel binary streams.
    iOpenCL::KernelData data;
    data.kernelBinary = std::make_unique<Util::BinaryStream>();

    m_ContextProvider.KernelIsDebuggable = kernel->m_SupportsDebugging;
    m_StateProcessor.CreateKernelBinary(
        reinterpret_cast<const char *>(kernel->getProgramOutput().m_programBin),
        kernel->getProgramOutput().m_programSize, kernel->m_kernelInfo,
        *m_programInfo, kernel->m_btiLayout, *(data.kernelBinary),
        m_pSystemThreadKernelOutput,
        kernel->getProgramOutput().m_unpaddedProgramSize);

    if (IGC_IS_FLAG_ENABLED(ShaderDumpEnable))
      Opts.Dumper->dumpCos(m_StateProcessor.m_oclStateDebugMessagePrintOut,
                           vc::legalizeShaderDumpName(
                               kernel->m_kernelInfo.m_kernelName + ".cos"));

    if (kernel->getProgramOutput().m_debugDataSize) {
      data.vcKernelDebugData = std::make_unique<Util::BinaryStream>();
      m_StateProcessor.CreateKernelDebugData(
          reinterpret_cast<const char *>(
              kernel->getProgramOutput().m_debugData),
          kernel->getProgramOutput().m_debugDataSize,
          reinterpret_cast<const char *>(
              kernel->getProgramOutput().m_debugDataGenISA),
          kernel->getProgramOutput().m_debugDataGenISASize,
          kernel->m_kernelInfo.m_kernelName, *data.vcKernelDebugData);
    }
    m_StateProcessor.m_oclStateDebugMessagePrintOut.clear();
    m_KernelBinaries.push_back(std::move(data));
  }
}

void CGen8CMProgram::GetZEBinary(llvm::raw_pwrite_stream &programBinary,
                                 unsigned pointerSizeInBytes) {
  // Contains buffer to an optional debug info. Should exists till zebuilder
  // is destroyed.
  std::unique_ptr<llvm::MemoryBuffer> DebugInfoHolder;

  const uint8_t *SpirvData = reinterpret_cast<const uint8_t *>(m_spirv.data());
  size_t SpirvSize = m_spirv.size();

  const uint8_t *OptsData = nullptr;
  size_t OptsSize = 0;
  if (m_opts) {
    OptsData = reinterpret_cast<const uint8_t *>(m_opts->data());
    OptsSize = m_opts->size();
  }

  iOpenCL::ZEBinaryBuilder zebuilder(m_Platform, pointerSizeInBytes == 8,
                                     *m_programInfo, SpirvData, SpirvSize,
                                     nullptr, 0, OptsData, OptsSize);
  zebuilder.setGfxCoreFamily(m_Platform.eRenderCoreFamily);

  for (const auto &kernel : m_kernels) {
    zebuilder.createKernel(
        reinterpret_cast<const char *>(kernel->getProgramOutput().m_programBin),
        kernel->getProgramOutput().m_programSize, kernel->m_kernelInfo,
        kernel->m_GRFSizeInBytes, kernel->m_btiLayout,
        kernel->getProgramOutput().m_VISAAsm,
        kernel->m_SupportsDebugging);
  }

  bool HasDebugInformation =
      std::any_of(m_kernels.begin(), m_kernels.end(),
                  [](const auto& kernel) {
                    return kernel->getProgramOutput().m_debugDataSize > 0;
                  });
  if (HasDebugInformation) {
    DebugInfoHolder = buildZeDebugInfo();
    if (DebugInfoHolder) {
      // Unfortunately, we do need const_cast here, since API requires void*
      void *BufferStart = const_cast<void *>(
          reinterpret_cast<const void *>(DebugInfoHolder->getBufferStart()));
      zebuilder.addElfSections(BufferStart, DebugInfoHolder->getBufferSize());
    }
  }
  dumpElfKernelMapFile();
  zebuilder.getBinaryObject(programBinary);
}

bool CGen8CMProgram::HasCrossThreadOffsetRelocations() {
  for (const auto &kernel : m_kernels) {
    for (const auto &reloc : kernel->getProgramOutput().m_relocs) {
      if (reloc.r_symbol == vISA::CROSS_THREAD_OFF_R0_RELOCATION_NAME) {
        return true;
      }
    }
  }
  return false;
}
