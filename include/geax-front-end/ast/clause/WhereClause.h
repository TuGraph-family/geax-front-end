/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_WHERECLAUSE_H_
#define GEAXFRONTEND_AST_CLAUSE_WHERECLAUSE_H_

#include "geax-front-end/ast/clause/ElementPredicate.h"
#include "geax-front-end/ast/expr/Expr.h"

namespace geax {
namespace frontend {

class WhereClause : public ElementPredicate {
public:
    WhereClause() : ElementPredicate(AstNodeType::kWhere), predicate_(nullptr) {}
    ~WhereClause() = default;

    void setPredicate(Expr* predicate) { predicate_ = predicate; }
    Expr* predicate() const { return predicate_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    Expr* predicate_;
};  // class WhereClause

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_WHERECLAUSE_H_
