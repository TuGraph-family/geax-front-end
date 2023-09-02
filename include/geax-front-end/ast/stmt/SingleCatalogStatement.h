/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_SINGLECATALOGSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_SINGLECATALOGSTATEMENT_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class SingleCatalogStatement : public AstNode {
public:
    explicit SingleCatalogStatement(AstNodeType nodeType) : AstNode(nodeType) {}
    ~SingleCatalogStatement() = default;
};  // class SingleCatalogStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_SINGLECATALOGSTATEMENT_H_
