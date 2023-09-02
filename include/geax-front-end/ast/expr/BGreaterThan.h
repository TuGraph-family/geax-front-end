/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BGREATERTHAN_H_
#define GEAXFRONTEND_AST_EXPR_BGREATERTHAN_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BGreaterThan : public BinaryOp {
public:
    BGreaterThan() : BinaryOp(AstNodeType::kBGreaterThan) {}
    ~BGreaterThan() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BGreaterThan

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BGREATERTHAN_H_
