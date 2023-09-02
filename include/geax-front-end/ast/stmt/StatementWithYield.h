/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_STATEMENTWITHYIELD_H_
#define GEAXFRONTEND_AST_STMT_STATEMENTWITHYIELD_H_

#include "geax-front-end/ast/AstNode.h"
#include "geax-front-end/ast/clause/YieldField.h"
#include "geax-front-end/ast/stmt/Statement.h"

namespace geax {
namespace frontend {

class StatementWithYield : public AstNode {
public:
    StatementWithYield()
        : AstNode(AstNodeType::kStatementWithYield), yield_(nullptr), statement_(nullptr) {}
    ~StatementWithYield() = default;

    void setYield(YieldField* yield) { yield_ = yield; }
    YieldField* yield() const { return yield_; }

    void setStatement(Statement* statement) { statement_ = statement; }
    Statement* statement() const { return statement_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    YieldField* yield_;
    Statement* statement_;
};  // class StatementWithYield

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_STATEMENTWITHYIELD_H_
