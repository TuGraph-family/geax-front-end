/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_SETSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_SETSTATEMENT_H_

#include "geax-front-end/ast/clause/SetItem.h"
#include "geax-front-end/ast/stmt/PrimitiveDataModifyStatement.h"

namespace geax {
namespace frontend {

class SetStatement : public PrimitiveDataModifyStatement {
public:
    SetStatement() : PrimitiveDataModifyStatement(AstNodeType::kSetStatement) {}
    ~SetStatement() = default;

    void appendItem(SetItem* item) { items_.emplace_back(item); }
    void setItems(std::vector<SetItem*>&& items) { items_ = std::move(items); }
    const std::vector<SetItem*>& items() const { return items_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    std::vector<SetItem*> items_;
};  // class SetStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_SETSTATEMENT_H_
