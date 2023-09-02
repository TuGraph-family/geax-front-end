/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_EDGELIKE_H_
#define GEAXFRONTEND_AST_CLAUSE_EDGELIKE_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class EdgeLike : public AstNode {
public:
    explicit EdgeLike(AstNodeType type) : AstNode(type) {}
    ~EdgeLike() = default;
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_EDGELIKE_H_
