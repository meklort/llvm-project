//===--- PropertyDeclarationCheck.h - clang-tidy-----------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_OBJC_PROPERTY_DECLARATION_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_OBJC_PROPERTY_DECLARATION_H

#include "../ClangTidy.h"
#include <string>
#include <vector>

namespace clang {
namespace tidy {
namespace objc {

/// Finds Objective-C property declarations which
/// are not in Lower Camel Case.
///
/// The format of property should look like:
/// @property(nonatomic) NSString *lowerCamelCase;
///
/// For the user-facing documentation see:
/// http://clang.llvm.org/extra/clang-tidy/checks/objc-property-declaration.html
class PropertyDeclarationCheck : public ClangTidyCheck {
public:
  PropertyDeclarationCheck(StringRef Name, ClangTidyContext *Context);
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
  void storeOptions(ClangTidyOptions::OptionMap &Options) override;

private:
  const std::vector<std::string> SpecialAcronyms;
  const bool IncludeDefaultAcronyms;
  std::vector<std::string> EscapedAcronyms;
};

} // namespace objc
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_OBJC_PROPERTY_DECLARATION_H
