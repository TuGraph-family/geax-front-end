/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_SCHEMAREF_H_
#define GEAXFRONTEND_AST_CLAUSE_SCHEMAREF_H_

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

#endif  // GEAXFRONTEND_AST_CLAUSE_SCHEMAREF_H_
