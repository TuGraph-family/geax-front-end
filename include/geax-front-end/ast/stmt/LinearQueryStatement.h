/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_LINEARQUERYSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_LINEARQUERYSTATEMENT_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class LinearQueryStatement : public AstNode {
public:
    explicit LinearQueryStatement(AstNodeType nodeType) : AstNode(nodeType) {}
    ~LinearQueryStatement() = default;
};  // class LinearQueryStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_LINEARQUERYSTATEMENT_H_
