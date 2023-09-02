/**
 * Copyright (c) 2022-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Yaochi <boyao.zby@alibaba-inc.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_QUERYCONJUNCTIONTYPE_H_
#define GEAXFRONTEND_AST_STMT_QUERYCONJUNCTIONTYPE_H_

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

#endif  // GEAXFRONTEND_AST_STMT_QUERYCONJUNCTIONTYPE_H_
