/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BNOTEQUAL_H_
#define GEAXFRONTEND_AST_EXPR_BNOTEQUAL_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BNotEqual : public BinaryOp {
public:
    BNotEqual() : BinaryOp(AstNodeType::kBNotEqual) {}
    ~BNotEqual() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BNotEqual

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BNOTEQUAL_H_
