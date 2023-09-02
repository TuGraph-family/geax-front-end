/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_ISNULL_H_
#define GEAXFRONTEND_AST_EXPR_ISNULL_H_

#include "geax-front-end/ast/expr/UnaryOp.h"

namespace geax {
namespace frontend {

class IsNull : public UnaryOp {
public:
    IsNull() : UnaryOp(AstNodeType::kIsNull) {}
    ~IsNull() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class IsNull

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_ISNULL_H_
