/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_FILTERSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_FILTERSTATEMENT_H_

#include "geax-front-end/ast/expr/Expr.h"
#include "geax-front-end/ast/stmt/SimpleQueryStatement.h"

namespace geax {
namespace frontend {

class FilterStatement : public SimpleQueryStatement {
public:
    FilterStatement()
        : SimpleQueryStatement(AstNodeType::kFilterStatement), predicate_(nullptr) {}
    ~FilterStatement() = default;

    void setPredicate(Expr* predicate) { predicate_ = predicate; }
    Expr* predicate() const { return predicate_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    Expr* predicate_;
};  // class FilterStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_FILTERSTATEMENT_H_
