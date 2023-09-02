/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BNOTSMALLERTHAN_H_
#define GEAXFRONTEND_AST_EXPR_BNOTSMALLERTHAN_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BNotSmallerThan : public BinaryOp {
public:
    BNotSmallerThan() : BinaryOp(AstNodeType::kBNotSmallerThan) {}
    ~BNotSmallerThan() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BNotSmallerThan

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BNOTSMALLERTHAN_H_
