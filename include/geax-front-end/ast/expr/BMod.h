/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BMOD_H_
#define GEAXFRONTEND_AST_EXPR_BMOD_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BMod : public BinaryOp {
public:
    BMod() : BinaryOp(AstNodeType::kBMod) {}
    ~BMod() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BMod

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BMOD_H_
