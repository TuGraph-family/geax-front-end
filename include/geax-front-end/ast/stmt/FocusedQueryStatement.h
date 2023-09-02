/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_FOCUSEDQUERYSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_FOCUSEDQUERYSTATEMENT_H_

#include "geax-front-end/ast/stmt/LinearQueryStatement.h"
#include "geax-front-end/ast/stmt/PrimitiveResultStatement.h"

namespace geax {
namespace frontend {

class FocusedQueryStatement : public LinearQueryStatement {
public:
    FocusedQueryStatement()
        : LinearQueryStatement(AstNodeType::kFocusedQueryStatement), resultStatement_(nullptr) {}
    ~FocusedQueryStatement() = default;

    void appendQuery(std::string&& graphRef, SimpleQueryStatement* queryStatement) {
        queryList_.emplace_back(std::move(graphRef), queryStatement);
    }
    void setQueryList(std::vector<std::tuple<std::string, SimpleQueryStatement*>>&& queryList) {
        queryList_ = std::move(queryList);
    }
    const std::vector<std::tuple<std::string, SimpleQueryStatement*>>& queryList() const {
        return queryList_;
    }

    void setResultStatement(PrimitiveResultStatement* resultStatement) {
        resultStatement_ = resultStatement;
    }
    PrimitiveResultStatement* resultStatement() const { return resultStatement_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    std::vector<std::tuple<std::string, SimpleQueryStatement*>> queryList_;
    PrimitiveResultStatement* resultStatement_;
};  // class FocusedQueryStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_FOCUSEDQUERYSTATEMENT_H_
