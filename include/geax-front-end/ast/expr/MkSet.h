/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_MKSET_H_
#define GEAXFRONTEND_AST_EXPR_MKSET_H_

#include "geax-front-end/ast/expr/Expr.h"

namespace geax {
namespace frontend {

class MkSet : public Expr {
public:
    MkSet() : Expr(AstNodeType::kMkSet) {}
    ~MkSet() = default;

    void appendElem(Expr* expr) { elems_.emplace_back(expr); }
    void setElems(std::vector<Expr*>&& elems) { elems_ = std::move(elems); }
    const std::vector<Expr*>& elems() const { return elems_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    std::vector<Expr*> elems_;
};  // class MkSet

inline bool MkSet::equals(const Expr& other) const {
    const auto& expr = static_cast<const MkSet&>(other);
    bool ret = elems_.size() == expr.elems_.size();
    for (auto i = 0u; i < elems_.size() && ret; ++i) {
        ret = (nullptr != elems_[i]) && (nullptr != expr.elems_[i]);
        ret = ret && *elems_[i] == *expr.elems_[i];
    }
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_MKSET_H_
