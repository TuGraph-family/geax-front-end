// Copyright (c) 2020-2025 AntGroup Inc. All Rights Reserved.
// Author:
//   fangji.hcm <fangji.hcm@antgroup.com>
//
#ifndef GEAXFRONTEND_AST_STMT_KILLSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_KILLSTATEMENT_H_

#include "geax-front-end/ast/stmt/Statement.h"
namespace geax {
namespace frontend {
class KillStatement : public Statement {
public:
    KillStatement() : Statement(AstNodeType::kKillStatement) {}
    virtual ~KillStatement() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

    void setId(uint64_t id) { id_ = id; }

    bool id() const { return id_; }

    void setQuery(bool flag) { query_ = flag; }

    bool isQuery() const { return query_; }

private:
    uint64_t id_;
    bool query_{true};
};  // class KillStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_KILLSTATEMENT_H_
