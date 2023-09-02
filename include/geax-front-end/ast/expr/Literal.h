/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_LITERAL_H_
#define GEAXFRONTEND_AST_EXPR_LITERAL_H_

#include "geax-front-end/ast/expr/Expr.h"

namespace geax {
namespace frontend {

class Literal : public Expr {
public:
    explicit Literal(AstNodeType type) : Expr(type) {}
    ~Literal() = default;
};  // class Literal

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_LITERAL_H_
