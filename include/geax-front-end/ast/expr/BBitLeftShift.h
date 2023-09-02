/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BBITLEFTSHIFT_H_
#define GEAXFRONTEND_AST_EXPR_BBITLEFTSHIFT_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BBitLeftShift : public BinaryOp {
public:
    BBitLeftShift() : BinaryOp(AstNodeType::kBBitRightShift) {}
    ~BBitLeftShift() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BBitLeftShift

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BBITLEFTSHIFT_H_
