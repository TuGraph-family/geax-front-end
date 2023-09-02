/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_BINDINGVAR_H_
#define GEAXFRONTEND_AST_CLAUSE_BINDINGVAR_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class BindingVar : public AstNode {
public:
    explicit BindingVar(AstNodeType nodeType) : AstNode(nodeType) {}
    ~BindingVar() = default;
};  // class BindingVar

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_BINDINGVAR_H_
