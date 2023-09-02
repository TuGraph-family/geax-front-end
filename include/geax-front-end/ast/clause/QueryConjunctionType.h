/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_QUERYCONJUNCTIONTYPE_H_
#define GEAXFRONTEND_AST_CLAUSE_QUERYCONJUNCTIONTYPE_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class QueryConjunctionType : public AstNode {
public:
    explicit QueryConjunctionType(AstNodeType nodeType) : AstNode(nodeType) {}
    ~QueryConjunctionType() = default;
};  // class QueryConjunctionType

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_QUERYCONJUNCTIONTYPE_H_
