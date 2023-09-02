/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_SIMPLEQUERYSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_SIMPLEQUERYSTATEMENT_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class SimpleQueryStatement : public AstNode {
public:
    explicit SimpleQueryStatement(AstNodeType nodeType) : AstNode(nodeType) {}
    ~SimpleQueryStatement() = default;
};  // class SimpleQueryStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_SIMPLEQUERYSTATEMENT_H_
