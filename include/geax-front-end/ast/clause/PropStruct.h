/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_PROPSTRUCT_H_
#define GEAXFRONTEND_AST_CLAUSE_PROPSTRUCT_H_

#include "geax-front-end/ast/clause/ElementPredicate.h"
#include "geax-front-end/ast/expr/Expr.h"

namespace geax {
namespace frontend {

class PropStruct : public ElementPredicate {
public:
    PropStruct() : ElementPredicate(AstNodeType::kPropStruct) {}
    ~PropStruct() = default;

    void appendProperty(std::string&& key, Expr* value) {
        properties_.emplace_back(std::move(key), value);
    }
    void setProperties(std::vector<std::tuple<std::string, Expr*>>&& properties) {
        properties_ = std::move(properties);
    }
    const std::vector<std::tuple<std::string, Expr*>>& properties() const { return properties_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    std::vector<std::tuple<std::string, Expr*>> properties_;
};  // class PropStruct

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_PROPSTRUCT_H_
