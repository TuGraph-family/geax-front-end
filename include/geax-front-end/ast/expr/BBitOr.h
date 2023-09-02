/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BBITOR_H_
#define GEAXFRONTEND_AST_EXPR_BBITOR_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BBitOr : public BinaryOp {
public:
    BBitOr() : BinaryOp(AstNodeType::kBBitOr) {}
    ~BBitOr() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BBitOr

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BBITOR_H_
