/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_ISNORMALIZED_H_
#define GEAXFRONTEND_AST_EXPR_ISNORMALIZED_H_

#include "geax-front-end/ast/expr/UnaryOp.h"

namespace geax {
namespace frontend {

class IsNormalized : public UnaryOp {
public:
    IsNormalized() : UnaryOp(AstNodeType::kIsNormalized) {}
    ~IsNormalized() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class IsNormalized

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_ISNORMALIZED_H_
