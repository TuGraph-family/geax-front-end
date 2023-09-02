/**
 * Copyright (c) 2022-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Yaochi <boyao.zby@alibaba-inc.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_SCHEMAREF_H_
#define GEAXFRONTEND_AST_STMT_SCHEMAREF_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class SchemaRef : public AstNode {
public:
    explicit SchemaRef(AstNodeType nodeType) : AstNode(nodeType) {}
    ~SchemaRef() = default;
};  // class SchemaRef

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_SCHEMAREF_H_
