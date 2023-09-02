/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_VNONE_H_
#define GEAXFRONTEND_AST_EXPR_VNONE_H_

#include "geax-front-end/ast/expr/Literal.h"

namespace geax {
namespace frontend {

class VNone : public Literal {
public:
    VNone() : Literal(AstNodeType::kVNone) {}
    ~VNone() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr&) const override { return true; }
};  // class VNone

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_VNONE_H_
