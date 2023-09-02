/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_YIELDFIELD_H_
#define GEAXFRONTEND_AST_CLAUSE_YIELDFIELD_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class YieldField : public AstNode {
public:
    YieldField() : AstNode(AstNodeType::kYieldField) {}
    ~YieldField() = default;

    void appendItem(std::string&& name, std::string&& alias) {
        items_.emplace_back(std::move(name), std::move(alias));
    }
    void setItems(std::vector<std::tuple<std::string, std::string>>&& items) {
        items_ = std::move(items);
    }
    const std::vector<std::tuple<std::string, std::string>>& items() const { return items_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    std::vector<std::tuple<std::string, std::string>> items_;
};  // class YieldField

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_YIELDFIELD_H_
