/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_BSAFEEQUAL_H_
#define GEAXFRONTEND_AST_EXPR_BSAFEEQUAL_H_

#include "geax-front-end/ast/expr/BinaryOp.h"

namespace geax {
namespace frontend {

class BSafeEqual : public BinaryOp {
public:
    BSafeEqual() : BinaryOp(AstNodeType::kBSafeEqual) {}
    ~BSafeEqual() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BSafeEqual

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_BSAFEEQUAL_H_
