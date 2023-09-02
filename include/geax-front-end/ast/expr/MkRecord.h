/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_MKRECORD_H_
#define GEAXFRONTEND_AST_EXPR_MKRECORD_H_

#include "geax-front-end/ast/expr/Expr.h"

namespace geax {
namespace frontend {

class MkRecord : public Expr {
public:
    MkRecord() : Expr(AstNodeType::kMkRecord) {}
    ~MkRecord() = default;

    void appendElem(std::string&& k, Expr* v) { elems_.emplace_back(std::move(k), v); }
    void setElems(std::vector<std::tuple<std::string, Expr*>>&& elems) {
        elems_ = std::move(elems);
    }
    const std::vector<std::tuple<std::string, Expr*>>& elems() const { return elems_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    std::vector<std::tuple<std::string, Expr*>> elems_;
};  // class MkRecord

inline bool MkRecord::equals(const Expr& other) const {
    const auto& expr = static_cast<const MkRecord&>(other);
    bool ret = elems_.size() == expr.elems_.size();
    for (auto i = 0u; i < elems_.size() && ret; ++i) {
        ret = (nullptr != std::get<1>(elems_[i])) && (nullptr != std::get<1>(expr.elems_[i]));
        ret = ret && std::get<0>(elems_[i]) == std::get<0>(expr.elems_[i]);
        ret = ret && (*std::get<1>(elems_[i]) == *std::get<1>(expr.elems_[i]));
    }
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_MKRECORD_H_
