/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_VSOME_H_
#define GEAXFRONTEND_AST_EXPR_VSOME_H_

#include "geax-front-end/ast/expr/UnaryOp.h"

namespace geax {
namespace frontend {

class VSome : public UnaryOp {
public:
    VSome() : UnaryOp(AstNodeType::kVSome) {}
    ~VSome() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class VSome

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_VSOME_H_
