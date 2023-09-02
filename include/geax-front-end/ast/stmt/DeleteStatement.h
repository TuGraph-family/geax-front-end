/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_DELETESTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_DELETESTATEMENT_H_

#include "geax-front-end/ast/stmt/PrimitiveDataModifyStatement.h"

namespace geax {
namespace frontend {

class DeleteStatement : public PrimitiveDataModifyStatement {
public:
    DeleteStatement() : PrimitiveDataModifyStatement(AstNodeType::kDeleteStatement) {}
    ~DeleteStatement() = default;

    void appendItem(std::string&& item) { items_.emplace_back(std::move(item)); }
    void setItems(std::vector<std::string>&& items) { items_ = std::move(items); }
    const std::vector<std::string>& items() const { return items_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    std::vector<std::string> items_;
};  // class DeleteStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_DELETESTATEMENT_H_
