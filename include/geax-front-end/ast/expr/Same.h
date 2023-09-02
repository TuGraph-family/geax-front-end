/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_SAME_H_
#define GEAXFRONTEND_AST_EXPR_SAME_H_

#include "geax-front-end/ast/expr/Expr.h"

namespace geax {
namespace frontend {

class Same : public Expr {
public:
    Same() : Expr(AstNodeType::kSame) {}
    ~Same() = default;

    void appendItem(Expr* item) { items_.emplace_back(item); }
    void setItems(std::vector<Expr*>&& items) { items_ = std::move(items); }
    const std::vector<Expr*>& items() const { return items_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    std::vector<Expr*> items_;
};  // class Same

inline bool Same::equals(const Expr& other) const {
    const auto& expr = static_cast<const Same&>(other);
    bool ret = expr.items_.size() == items_.size();
    for (auto i = 0u; i < items_.size() && ret; ++i) {
        ret = (nullptr != items_[i]) && (nullptr != expr.items_[i]);
        ret = ret && *items_[i] == *expr.items_[i];
    }
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_SAME_H_
