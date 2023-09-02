/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_VNULL_H_
#define GEAXFRONTEND_AST_EXPR_VNULL_H_

#include "geax-front-end/ast/expr/Literal.h"

namespace geax {
namespace frontend {

class VNull : public Literal {
public:
    VNull() : Literal(AstNodeType::kVNull) {}
    ~VNull() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr&) const override { return true; }
};  // class VNull

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_VNULL_H_
