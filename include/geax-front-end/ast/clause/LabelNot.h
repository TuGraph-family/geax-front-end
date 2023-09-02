/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_LABELNOT_H_
#define GEAXFRONTEND_AST_CLAUSE_LABELNOT_H_

#include "geax-front-end/ast/clause/LabelTree.h"

namespace geax {
namespace frontend {

class LabelNot : public LabelTree {
public:
    LabelNot() : LabelTree(AstNodeType::kLabelNot), expr_(nullptr) {}
    ~LabelNot() = default;

    void setExpr(LabelTree* expr) { expr_ = expr; }
    LabelTree* expr() const { return expr_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const LabelTree& other) const override;

    LabelTree* expr_;
};

inline bool LabelNot::equals(const LabelTree& other) const {
    const auto& LabelTree = static_cast<const LabelNot&>(other);
    bool ret = (nullptr != expr_) && (nullptr != LabelTree.expr_) && *expr_ == *LabelTree.expr_;
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_LABELNOT_H_
