/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_ELEMENTFILLER_H_
#define GEAXFRONTEND_AST_CLAUSE_ELEMENTFILLER_H_

#include <optional>
#include <vector>

#include "geax-front-end/ast/AstNode.h"
#include "geax-front-end/ast/clause/ElementPredicate.h"
#include "geax-front-end/ast/clause/LabelTree.h"
#include "geax-front-end/ast/expr/Expr.h"

namespace geax {
namespace frontend {

/**
 * A ElementFiller represents a common part of vertex and edge patterns.
 */
class ElementFiller : public AstNode {
public:
    ElementFiller() : AstNode(AstNodeType::kElementFiller) {}
    ~ElementFiller() = default;

    void setV(std::string&& v) { v_ = std::move(v); }
    const std::optional<std::string>& v() const { return v_; }

    void setLabel(LabelTree* label) { label_ = label; }
    const std::optional<LabelTree*>& label() const { return label_; }

    void appendPredicate(ElementPredicate* predicate) {
        elementPredicates_.emplace_back(predicate);
    }
    void setPredicates(std::vector<ElementPredicate*>&& elementPredicates) {
        elementPredicates_ = std::move(elementPredicates);
    }
    const std::vector<ElementPredicate*>& predicates() const { return elementPredicates_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    std::optional<std::string> v_;  // also called element variable
    std::optional<LabelTree*> label_;
    std::vector<ElementPredicate*> elementPredicates_;
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_ELEMENTFILLER_H_
