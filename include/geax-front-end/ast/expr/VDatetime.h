/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_VDATETIME_H_
#define GEAXFRONTEND_AST_EXPR_VDATETIME_H_

#include "geax-front-end/ast/expr/Literal.h"

namespace geax {
namespace frontend {

class VDatetime : public Literal {
public:
    VDatetime() : Literal(AstNodeType::kVDatetime) {}
    ~VDatetime() = default;

    void setVal(std::string&& val) { val_ = val; }
    const std::string& val() const { return val_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    std::string val_;
};  // class VDatetime

inline bool VDatetime::equals(const Expr& other) const {
    const auto& expr = static_cast<const VDatetime&>(other);
    return val_ == expr.val_;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_VDATETIME_H_
