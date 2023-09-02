/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BEQUAL_H_
#define GEAXFRONTEND_AST_EXPR_BEQUAL_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BEqual : public BinaryOp {
public:
    BEqual() : BinaryOp(AstNodeType::kBEqual) {}
    ~BEqual() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BEqual

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BEQUAL_H_
