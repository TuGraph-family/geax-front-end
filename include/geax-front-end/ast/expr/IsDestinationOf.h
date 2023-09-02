/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_ISDESTINATIONOF_H_
#define GEAXFRONTEND_AST_EXPR_ISDESTINATIONOF_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class IsDestinationOf : public BinaryOp {
public:
    IsDestinationOf() : BinaryOp(AstNodeType::kIsDestinationOf) {}
    ~IsDestinationOf() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class IsDestinationOf

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_ISDESTINATIONOF_H_
