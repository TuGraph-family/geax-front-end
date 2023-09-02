/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BBITXOR_H_
#define GEAXFRONTEND_AST_EXPR_BBITXOR_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BBitXor : public BinaryOp {
public:
    BBitXor() : BinaryOp(AstNodeType::kBBitXor) {}
    ~BBitXor() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BBitXor

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BBITXOR_H_
