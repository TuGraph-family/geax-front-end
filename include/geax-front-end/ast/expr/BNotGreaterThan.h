/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BNOTGREATERTHAN_H_
#define GEAXFRONTEND_AST_EXPR_BNOTGREATERTHAN_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BNotGreaterThan : public BinaryOp {
public:
    BNotGreaterThan() : BinaryOp(AstNodeType::kBNotGreaterThan) {}
    ~BNotGreaterThan() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BNotGreaterThan

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BNOTGREATERTHAN_H_
