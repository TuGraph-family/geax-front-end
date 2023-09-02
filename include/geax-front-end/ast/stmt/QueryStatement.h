/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_QUERYSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_QUERYSTATEMENT_H_

#include "geax-front-end/ast/stmt/Statement.h"
#include "geax-front-end/ast/stmt/JoinQueryExpression.h"

namespace geax {
namespace frontend {

class QueryStatement : public Statement {
public:
    QueryStatement() : Statement(AstNodeType::kQueryStatement), joinQuery_(nullptr) {}
    ~QueryStatement() = default;

    void setJoinQuery(JoinQueryExpression* joinQuery) { joinQuery_ = joinQuery; }
    JoinQueryExpression* joinQuery() const { return joinQuery_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    JoinQueryExpression* joinQuery_;
};  // class QueryStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_QUERYSTATEMENT_H_
