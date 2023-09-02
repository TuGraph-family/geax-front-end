/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_STATEMENT_H_
#define GEAXFRONTEND_AST_STMT_STATEMENT_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

/**
 * An Statement represents a basic statement in a query.
 *
 * The layout of the query statment family should be as the follows:
 *
 * ProcedureBody
 *    |
 *    v
 * StatementWithYield --> Statement
 *
 * A Statement could be (we only have query statements currently)
 * - CatalogModifyStatement
 * - LinearDataModifyingStatement
 * - CompositeQueryStatement (QueryStatement -> JOIN -> CompositeQueryStatement)
 *      A CompositeQueryStatement includes linearQueryStatements
 */
class Statement : public AstNode {
public:
    explicit Statement(AstNodeType nodeType) : AstNode(nodeType) {}
    ~Statement() = default;
};  // class Statement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_STATEMENT_H_
