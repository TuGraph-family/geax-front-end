/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BBITRIGHTSHIFT_H_
#define GEAXFRONTEND_AST_EXPR_BBITRIGHTSHIFT_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BBitRightShift : public BinaryOp {
public:
    BBitRightShift() : BinaryOp(AstNodeType::kBBitRightShift) {}
    ~BBitRightShift() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BBitRightShift

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BBITRIGHTSHIFT_H_
