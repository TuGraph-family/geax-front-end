/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_SETSINGLEPROPERTY_H_
#define GEAXFRONTEND_AST_CLAUSE_SETSINGLEPROPERTY_H_

#include "geax-front-end/ast/clause/SetItem.h"
#include "geax-front-end/ast/expr/Expr.h"

namespace geax {
namespace frontend {

class SetSingleProperty : public SetItem {
public:
    SetSingleProperty() : SetItem(AstNodeType::kSetSingleProperty), value_(nullptr) {}
    ~SetSingleProperty() = default;

    void setV(std::string&& v) { v_ = std::move(v); }
    const std::string& v() const { return v_; }

    void setProperty(std::string&& property) { property_ = property; }
    const std::string& property() const { return property_; }

    void setValue(Expr* value) { value_ = value; }
    Expr* value() const { return value_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    std::string v_;
    std::string property_;
    Expr* value_;
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_SETSINGLEPROPERTY_H_
