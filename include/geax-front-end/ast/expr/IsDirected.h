/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_ISDIRECTED_H_
#define GEAXFRONTEND_AST_EXPR_ISDIRECTED_H_

#include "geax-front-end/ast/expr/UnaryOp.h"

namespace geax {
namespace frontend {

class IsDirected : public UnaryOp {
public:
    IsDirected() : UnaryOp(AstNodeType::kIsDirected) {}
    ~IsDirected() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class IsDirected

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_ISDIRECTED_H_
