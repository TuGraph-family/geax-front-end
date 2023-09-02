/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_TABLEFUNCTIONCLAUSE_H_
#define GEAXFRONTEND_AST_CLAUSE_TABLEFUNCTIONCLAUSE_H_

#include "geax-front-end/ast/clause/ElementPredicate.h"
#include "geax-front-end/ast/expr/Expr.h"

namespace geax {
namespace frontend {
class TableFunctionClause : public ElementPredicate {
public:
    TableFunctionClause() : ElementPredicate(AstNodeType::kTableFunction), function_(nullptr) {}
    ~TableFunctionClause() = default;

    void setFunction(Expr* function) { function_ = function; }
    Expr* function() const { return function_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    Expr* function_;
};
}  // end of namespace geabase
}  // end of namespace alibaba

#endif  // GEAXFRONTEND_AST_CLAUSE_TABLEFUNCTIONCLAUSE_H_
