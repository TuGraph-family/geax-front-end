/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_VTIME_H_
#define GEAXFRONTEND_AST_EXPR_VTIME_H_

#include "geax-front-end/ast/expr/Literal.h"

namespace geax {
namespace frontend {

class VTime : public Literal {
public:
    VTime() : Literal(AstNodeType::kVTime) {}
    ~VTime() = default;

    void setVal(std::string&& val) { val_ = std::move(val); }
    const std::string& val() const { return val_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    std::string val_;
};  // class VTime

inline bool VTime::equals(const Expr& other) const {
    const auto& expr = static_cast<const VTime&>(other);
    return val_ == expr.val_;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_VTIME_H_
