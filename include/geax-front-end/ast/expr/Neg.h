/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_NEG_H_
#define GEAXFRONTEND_AST_EXPR_NEG_H_

#include "geax-front-end/ast/expr/UnaryOp.h"

namespace geax {
namespace frontend {

class Neg : public UnaryOp {
public:
    Neg() : UnaryOp(AstNodeType::kNeg) {}
    ~Neg() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class Neg

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_NEG_H_
