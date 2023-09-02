/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_TILDE_H_
#define GEAXFRONTEND_AST_EXPR_TILDE_H_

#include "geax-front-end/ast/expr/UnaryOp.h"

namespace geax {
namespace frontend {

class Tilde : public UnaryOp {
public:
    Tilde() : UnaryOp(AstNodeType::kTilde) {}
    ~Tilde() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class Tilde

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_TILDE_H_
