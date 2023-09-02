/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_VDOUBLE_H_
#define GEAXFRONTEND_AST_EXPR_VDOUBLE_H_

#include "geax-front-end/ast/expr/Literal.h"

namespace geax {
namespace frontend {

class VDouble : public Literal {
public:
    VDouble() : Literal(AstNodeType::kVDouble), val_(0) {}
    ~VDouble() = default;

    void setVal(double val) { val_ = val; }
    double val() const { return val_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    double val_;
};  // class VDouble

inline bool VDouble::equals(const Expr& other) const {
    const auto& expr = static_cast<const VDouble&>(other);
    static constexpr auto DEPS = 1e-12;
    return std::abs(val_ - expr.val_) < DEPS;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_VDOUBLE_H_
