// Copyright (c) 2020-2025 AntGroup Inc. All Rights Reserved.
// Author:
//   fangji.hcm <fangji.hcm@antgroup.com>
//
#ifndef GEAXFRONTEND_AST_STMT_MANAGERSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_MANAGERSTATEMENT_H_

#include "geax-front-end/ast/stmt/Statement.h"

namespace geax {
namespace frontend {
class ManagerStatement : public Statement {
public:
    ManagerStatement() : Statement(AstNodeType::kManagerStatement) {}

    virtual ~ManagerStatement() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class ManagerStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_MANAGERSTATEMENT_H_
