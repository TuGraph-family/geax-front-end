/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_VBOOL_H_
#define GEAXFRONTEND_AST_EXPR_VBOOL_H_

#include "geax-front-end/ast/expr/Literal.h"

namespace geax {
namespace frontend {

class VBool : public Literal {
public:
    VBool() : Literal(AstNodeType::kVBool), val_(false) {}
    ~VBool() = default;

    void setVal(bool val) { val_ = val; }
    bool val() const { return val_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    bool val_;
};  // class VBool

inline bool VBool::equals(const Expr& other) const {
    const auto& expr = static_cast<const VBool&>(other);
    return val_ == expr.val_;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_VBOOL_H_
