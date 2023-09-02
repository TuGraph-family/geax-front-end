/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_VINT_H_
#define GEAXFRONTEND_AST_EXPR_VINT_H_

#include "geax-front-end/ast/expr/Literal.h"

namespace geax {
namespace frontend {

class VInt : public Literal {
public:
    VInt() : Literal(AstNodeType::kVInt), val_(0) {}
    ~VInt() = default;

    void setVal(int64_t val) { val_ = val; }
    int64_t val() const { return val_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    int64_t val_;
};  // class VInt

inline bool VInt::equals(const Expr& other) const {
    const auto& expr = static_cast<const VInt&>(other);
    return val_ == expr.val_;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_VINT_H_
