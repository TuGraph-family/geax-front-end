/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_AMBIENTLINEARQUERYSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_AMBIENTLINEARQUERYSTATEMENT_H_

#include "geax-front-end/ast/stmt/LinearQueryStatement.h"
#include "geax-front-end/ast/stmt/SimpleQueryStatement.h"

namespace geax {
namespace frontend {

/**
 * An AmbientLinearQueryStatement represents a stmt that have multiple prefixed reading
 * clauses and a trailing with/return clause.
 */
class AmbientLinearQueryStatement : public LinearQueryStatement {
public:
    AmbientLinearQueryStatement()
        : LinearQueryStatement(AstNodeType::kAmbientStatement), resultStatement_(nullptr) {}
    ~AmbientLinearQueryStatement() = default;

    void appendQueryStatement(SimpleQueryStatement* queryStatement) {
        queryStatements_.emplace_back(queryStatement);
    }
    void setQueryStatements(std::vector<SimpleQueryStatement*>&& queryStatements) {
        queryStatements_ = std::move(queryStatements);
    }
    const std::vector<SimpleQueryStatement*>& queryStatements() const { return queryStatements_; }

    void setResultStatement(PrimitiveResultStatement* resultStatement) {
        resultStatement_ = resultStatement;
    }
    PrimitiveResultStatement* resultStatement() const { return resultStatement_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    PrimitiveResultStatement* resultStatement_;
    std::vector<SimpleQueryStatement*> queryStatements_;
};  // class AmbientLinearQueryStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_AMBIENTLINEARQUERYSTATEMENT_H_
