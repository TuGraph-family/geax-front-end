/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BSUB_H_
#define GEAXFRONTEND_AST_EXPR_BSUB_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BSub : public BinaryOp {
public:
    BSub() : BinaryOp(AstNodeType::kBSub) {}
    ~BSub() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BSub

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BSUB_H_
