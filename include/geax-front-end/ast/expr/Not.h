/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_NOT_H_
#define GEAXFRONTEND_AST_EXPR_NOT_H_

#include "geax-front-end/ast/expr/UnaryOp.h"

namespace geax {
namespace frontend {

class Not : public UnaryOp {
public:
    Not() : UnaryOp(AstNodeType::kNot) {}
    ~Not() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class Not

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_NOT_H_
