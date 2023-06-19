/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#ifndef IGCLLVM_ADT_OPTIONAL_H
#define IGCLLVM_ADT_OPTIONAL_H

#include <llvm/ADT/Optional.h>
#include <optional>

namespace IGCLLVM {
template <typename T> class Optional : public
#if LLVM_VERSION_MAJOR < 16
llvm::Optional<T> 
#else
std::optional<T>
#endif
{
public:
#if LLVM_VERSION_MAJOR < 16
  using BaseT = llvm::Optional<T>;
#else
  using BaseT = std::optional<T>;
#endif
  constexpr Optional(const BaseT &O) : BaseT(O) {}
  constexpr Optional(BaseT &&O) : BaseT(std::move(O)) {}

/* ---------------------|
| Deprecated in LLVM 15 |
| -------------------- */
#if LLVM_VERSION_MAJOR < 15
  template <typename U> constexpr T value_or(U &&alt) const & {
    return this->getValueOr(std::forward<U>(alt));
  }

  template <typename U> T value_or(U &&alt) && {
    return this->getValueOr(std::forward<U>(alt));
  }
#endif

  constexpr T &value() &noexcept {
#if LLVM_VERSION_MAJOR < 16
    return this->getValue();
#else
    assert(this.has_value());
    return *this;
#endif
  }

  constexpr bool hasValue() const noexcept {
#if LLVM_VERSION_MAJOR < 16
    return this->hasValue();
#else
    return this.has_value();
#endif
  }
};

template <typename T>
Optional<T> wrapOptional(const llvm::Optional<T> &O) {
  return { O };
}
} // namespace IGCLLVM

#endif // IGCLLVM_ADT_OPTIONAL_H
