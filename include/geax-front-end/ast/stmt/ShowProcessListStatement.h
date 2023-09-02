// Copyright (c) 2020-2025 AntGroup Inc. All Rights Reserved.
// Author:
//   fangji.hcm <fangji.hcm@antgroup.com>
//
#ifndef GEAXFRONTEND_AST_STMT_SHOWPROCESSLISTSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_SHOWPROCESSLISTSTATEMENT_H_

#include "geax-front-end/ast/stmt/Statement.h"

namespace geax {
namespace frontend {
class ShowProcessListStatement : public Statement {
public:
    ShowProcessListStatement() : Statement(AstNodeType::kShowProcessListStatement) {}

    virtual ~ShowProcessListStatement() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class ShowProcessListStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_SHOWPROCESSLISTSTATEMENT_H_
