/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_GETFIELD_H_
#define GEAXFRONTEND_AST_EXPR_GETFIELD_H_

#include "geax-front-end/ast/expr/UnaryOp.h"

namespace geax {
namespace frontend {

class GetField : public UnaryOp {
public:
    GetField() : UnaryOp(AstNodeType::kGetField) {}
    ~GetField() = default;

    void setFieldName(std::string&& fieldName) { fieldName_ = std::move(fieldName); }
    const std::string& fieldName() const { return fieldName_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    std::string fieldName_;
};  // class GetField

inline bool GetField::equals(const Expr& other) const {
    const auto& expr = static_cast<const GetField&>(other);
    bool ret = UnaryOp::equals(other) && fieldName_ == expr.fieldName_;
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_GETFIELD_H_
