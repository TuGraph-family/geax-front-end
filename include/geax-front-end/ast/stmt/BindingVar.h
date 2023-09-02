/**
 * Copyright (c) 2022-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Yaochi <boyao.zby@alibaba-inc.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_BINDINGVAR_H_
#define GEAXFRONTEND_AST_STMT_BINDINGVAR_H_

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

#endif  // GEAXFRONTEND_AST_STMT_BINDINGVAR_H_
