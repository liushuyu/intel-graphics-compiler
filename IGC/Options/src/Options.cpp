/*========================== begin_copyright_notice ============================

Copyright (C) 2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include "igc/Options/Options.h"

#include <llvmWrapper/Option/OptTable.h>
#include <llvm/Option/Option.h>
#include <llvm/ADT/ArrayRef.h>
#include <llvm/ADT/StringRef.h>

using namespace IGC::options;
using namespace llvm::opt;
using llvm::raw_ostream;

#define PREFIX(NAME, VALUE) static IGCLLVM::igc_prefixes_list_t API_##NAME = VALUE;
#include "igc/Options/ApiOptions.inc"
#undef PREFIX

#define PREFIX(NAME, VALUE) static IGCLLVM::igc_prefixes_list_t INTERNAL_##NAME = VALUE;
#include "igc/Options/InternalOptions.inc"
#undef PREFIX

static const OptTable::Info ApiInfoTable[] = {
#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, ALIASARGS, FLAGS, PARAM,  \
               HELPTEXT, METAVAR, VALUES)                                      \
  {API_##PREFIX,        NAME,  HELPTEXT, METAVAR,          api::OPT_##ID,      \
   Option::KIND##Class, PARAM, FLAGS,    api::OPT_##GROUP, api::OPT_##ALIAS,   \
   ALIASARGS,           VALUES},
#include "igc/Options/ApiOptions.inc"
#undef OPTION
};

static const OptTable::Info InternalInfoTable[] = {
#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, ALIASARGS, FLAGS, PARAM,  \
               HELPTEXT, METAVAR, VALUES)                                      \
  {INTERNAL_##PREFIX,                                                          \
   NAME,                                                                       \
   HELPTEXT,                                                                   \
   METAVAR,                                                                    \
   internal::OPT_##ID,                                                         \
   Option::KIND##Class,                                                        \
   PARAM,                                                                      \
   FLAGS,                                                                      \
   internal::OPT_##GROUP,                                                      \
   internal::OPT_##ALIAS,                                                      \
   ALIASARGS,                                                                  \
   VALUES},
#include "igc/Options/InternalOptions.inc"
#undef OPTION
};

namespace {
class IGCApiOptTable : public IGCLLVM::IGCOptTable {
public:
  IGCApiOptTable() : IGCLLVM::IGCOptTable(ApiInfoTable) {
    IGCLLVM::IGCOptTable &Opt = *this;
    (void)Opt;
#define OPTTABLE_ARG_INIT
#include "igc/Options/ApiOptions.inc"
#undef OPTTABLE_ARG_INIT
  }
};

class IGCInternalOptTable : public IGCLLVM::IGCOptTable {
public:
  IGCInternalOptTable() : IGCLLVM::IGCOptTable(InternalInfoTable) {
    IGCLLVM::IGCOptTable &Opt = *this;
    (void)Opt;
#define OPTTABLE_ARG_INIT
#include "igc/Options/InternalOptions.inc"
#undef OPTTABLE_ARG_INIT
  }
};
} // namespace

static const IGCApiOptTable ApiOptionsTable;
static const IGCInternalOptTable InternalOptionsTable;

const OptTable &IGC::getApiOptTable() { return ApiOptionsTable; }
const OptTable &IGC::getInternalOptTable() { return InternalOptionsTable; }
