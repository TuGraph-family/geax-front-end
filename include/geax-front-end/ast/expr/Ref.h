/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_REF_H_
#define GEAXFRONTEND_AST_EXPR_REF_H_

#include "geax-front-end/ast/expr/Expr.h"

namespace geax {
namespace frontend {

class Ref : public Expr {
public:
    Ref() : Expr(AstNodeType::kRef) {}
    ~Ref() = default;

    void setName(std::string&& name) { name_ = std::move(name); }
    const std::string& name() const { return name_; }
    std::string& name() { return name_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    std::string name_;
};  // class Ref

inline bool Ref::equals(const Expr& other) const {
    const auto& expr = static_cast<const Ref&>(other);
    return name_ == expr.name_;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_REF_H_
