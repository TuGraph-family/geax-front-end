/**
 * Copyright (c) 2022-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_CAST_H_
#define GEAXFRONTEND_AST_EXPR_CAST_H_

#include "geax-front-end/ast/expr/UnaryOp.h"

namespace geax {
namespace frontend {

class Cast : public UnaryOp {
public:
    Cast() : UnaryOp(AstNodeType::kCast) {}
    ~Cast() = default;

    void setCastType(std::string&& type) { castType_ = std::move(type); }
    const std::string& castType() const { return castType_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    std::string castType_;
};  // class Cast

inline bool Cast::equals(const Expr& other) const {
    const auto& expr = static_cast<const Cast&>(other);
    bool ret = UnaryOp::equals(other) && castType_ == expr.castType_;
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_CAST_H_
