/**
 * Copyright (c) 2022-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Yaochi <boyao.zby@alibaba-inc.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_BINDINGVALUE_H_
#define GEAXFRONTEND_AST_STMT_BINDINGVALUE_H_

#include "geax-front-end/ast/stmt/BindingVar.h"

namespace geax {
namespace frontend {

class BindingValue : public BindingVar {
public:
    BindingValue() : BindingVar(AstNodeType::kBindingValue) {}
    ~BindingValue() = default;

    std::any accept(AstNodeVisitor& visitor) override {
        return visitor.visit(this);
    }

    DEFINE_FROM_AND_TO_JSON

private:
    DECLARE_JSON_FIELDS() {
        JSON_FIELD(type);
    }
};  // class BindingValue

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_BINDINGVALUE_H_
