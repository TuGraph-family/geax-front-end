/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BBITAND_H_
#define GEAXFRONTEND_AST_EXPR_BBITAND_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BBitAnd : public BinaryOp {
public:
    BBitAnd() : BinaryOp(AstNodeType::kBBitAnd) {}
    ~BBitAnd() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BBitAnd

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BBITAND_H_
