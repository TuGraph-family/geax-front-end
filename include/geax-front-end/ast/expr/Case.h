/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_CASE_H_
#define GEAXFRONTEND_AST_EXPR_CASE_H_

#include "geax-front-end/ast/expr/Expr.h"

namespace geax {
namespace frontend {

class Case : public Expr {
public:
    Case() : Expr(AstNodeType::kCase) {}
    ~Case() = default;

    void setInput(Expr* input) { input_ = input; }
    const std::optional<Expr*>& input() const { return input_; }

    void appendCaseBody(Expr* cond, Expr* result) { caseBodies_.emplace_back(cond, result); }
    void setCaseBodies(std::vector<std::tuple<Expr*, Expr*>>&& caseBodies) {
        caseBodies_ = std::move(caseBodies);
    }
    const std::vector<std::tuple<Expr*, Expr*>>& caseBodies() const { return caseBodies_; }

    void setElseBody(Expr* elseBody) { elseBody_ = elseBody; }
    const std::optional<Expr*>& elseBody() const { return elseBody_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    std::optional<Expr*> input_;
    std::vector<std::tuple<Expr*, Expr*>> caseBodies_;
    std::optional<Expr*> elseBody_;
};  // class Case

inline bool Case::equals(const Expr& other) const {
    const auto& expr = static_cast<const Case&>(other);
    bool ret = input_.has_value() == expr.input_.has_value();
    if (ret && input_.has_value()) {
        ret = *input_.value() == *expr.input_.value();
    }
    ret = ret && elseBody_.has_value() == expr.elseBody_.has_value();
    if (ret && elseBody_.has_value()) {
        ret = *elseBody_.value() == *expr.elseBody_.value();
    }
    ret = ret && caseBodies_.size() == expr.caseBodies_.size();
    for (auto i = 0u; i < caseBodies_.size() && ret; ++i) {
        ret = (nullptr != std::get<0>(caseBodies_[i])) &&
              (nullptr != std::get<0>(expr.caseBodies_[i])) &&
              (nullptr != std::get<1>(caseBodies_[i])) &&
              (nullptr != std::get<1>(expr.caseBodies_[i]));
        ret = ret && *std::get<0>(caseBodies_[i]) == *std::get<0>(expr.caseBodies_[i]);
        ret = ret && (*std::get<1>(caseBodies_[i]) == *std::get<1>(expr.caseBodies_[i]));
    }
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_CASE_H_
