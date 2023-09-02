/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_BINDINGVALUE_H_
#define GEAXFRONTEND_AST_CLAUSE_BINDINGVALUE_H_

#include "geax-front-end/ast/clause/BindingVar.h"

namespace geax {
namespace frontend {

class BindingValue : public BindingVar {
public:
    BindingValue() : BindingVar(AstNodeType::kBindingValue) {}
    ~BindingValue() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BindingValue

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_BINDINGVALUE_H_
