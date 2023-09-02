/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_UNARYOP_H_
#define GEAXFRONTEND_AST_EXPR_UNARYOP_H_

#include "geax-front-end/ast/expr/Expr.h"

namespace geax {
namespace frontend {

class UnaryOp : public Expr {
public:
    explicit UnaryOp(AstNodeType type) : Expr(type), expr_(nullptr) {}
    ~UnaryOp() = default;

    void setExpr(Expr* expr) { expr_ = expr; }
    Expr* expr() const { return expr_; }

protected:
    bool equals(const Expr& other) const override;

private:
    Expr* expr_;
};  // class UnaryOp

inline bool UnaryOp::equals(const Expr& other) const {
    const auto& expr = static_cast<const UnaryOp&>(other);
    bool ret = (nullptr != expr_) && (nullptr != expr.expr_) && *expr_ == *expr.expr_;
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_UNARYOP_H_
