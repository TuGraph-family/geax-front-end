/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BSMALLERTHAN_H_
#define GEAXFRONTEND_AST_EXPR_BSMALLERTHAN_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BSmallerThan : public BinaryOp {
public:
    BSmallerThan() : BinaryOp(AstNodeType::kBSmallerThan) {}
    ~BSmallerThan() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BSmallerThan

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BSMALLERTHAN_H_
