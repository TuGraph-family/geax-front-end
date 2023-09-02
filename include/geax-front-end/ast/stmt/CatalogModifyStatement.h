/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_CATALOGMODIFYSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_CATALOGMODIFYSTATEMENT_H_

#include "geax-front-end/ast/stmt/Statement.h"
#include "geax-front-end/ast/stmt/SingleCatalogStatement.h"

namespace geax {
namespace frontend {

class CatalogModifyStatement : public Statement {
public:
    CatalogModifyStatement() : Statement(AstNodeType::kCatalogModifyStatement) {}
    ~CatalogModifyStatement() = default;

    void appendStatement(SingleCatalogStatement* statement) { statements_.emplace_back(statement); }
    void setStatements(std::vector<SingleCatalogStatement*>&& statements) {
        statements_ = std::move(statements);
    }
    const std::vector<SingleCatalogStatement*>& statements() const { return statements_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    std::vector<SingleCatalogStatement*> statements_;
};  // class CatalogModifyStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_CATALOGMODIFYSTATEMENT_H_
