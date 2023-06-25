/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#ifndef IGCLLVM_ADT_OPTIONAL_H
#define IGCLLVM_ADT_OPTIONAL_H

#if LLVM_VERSION_MAJOR < 16
#include <llvm/ADT/Optional.h>
#endif
#include <cassert>
#include <optional>

#include "llvmWrapper/ADT/None.h"

namespace IGCLLVM {
#if LLVM_VERSION_MAJOR < 16
  template <typename T>
  using Optional = llvm::Optional<T>;

  template <typename T>
  Optional<T> wrapOptional(const IGCLLVM::Optional<T> &O) {
    return { O };
  }
  /* ---------------------|
  | Deprecated in LLVM 15 |
  | -------------------- */
#if 0
    template <typename U> constexpr T value_or(U &&alt) const & {
      return this->getValueOr(std::forward<U>(alt));
    }

    template <typename U> T value_or(U &&alt) && {
      return this->getValueOr(std::forward<U>(alt));
    }
#endif
#else
// compatibility layer
template <typename T> class Optional : public std::optional<T>
{
public:

  constexpr Optional<T>(): std::optional<T>() {}
  constexpr Optional<T>(const std::optional<T> &O): std::optional<T>(O) {}
  constexpr Optional<T>(std::nullopt_t O): std::optional<T>(O) {}
  constexpr Optional<T>(T &O): std::optional<T>(O) {}
  constexpr Optional<T>(T &&O): std::optional<T>(O) {}

  constexpr const T &getValue() const &noexcept {
    assert(this->has_value());
    const std::optional<T>* opt = this;
    return **opt;
  }

  T &getValue() &noexcept {
    assert(this->has_value());
    std::optional<T>* opt = this;
    return **opt;
  }

  constexpr bool hasValue() const noexcept {
    return this->has_value();
  }

  constexpr bool operator==(const Optional<T>& other) {
    return this->has_value() == other.has_value() &&
           (this->has_value() ? this->getValue() == other.getValue() : true);
  }
};

template <typename T>
Optional<T> wrapOptional(const std::optional<T> &O) {
  return Optional{ O };
}
#endif

} // namespace IGCLLVM

#endif // IGCLLVM_ADT_OPTIONAL_H
