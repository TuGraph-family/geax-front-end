/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BCONCAT_H_
#define GEAXFRONTEND_AST_EXPR_BCONCAT_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BConcat : public BinaryOp {
public:
    BConcat() : BinaryOp(AstNodeType::kBConcat) {}
    ~BConcat() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BConcat

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BCONCAT_H_
