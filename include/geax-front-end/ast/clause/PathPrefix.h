/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_PATHPREFIX_H_
#define GEAXFRONTEND_AST_CLAUSE_PATHPREFIX_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class PathPrefix : public AstNode {
public:
    explicit PathPrefix(AstNodeType type) : AstNode(type) {}
    ~PathPrefix() = default;
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_PATHPREFIX_H_
