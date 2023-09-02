/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_LABELOR_H_
#define GEAXFRONTEND_AST_CLAUSE_LABELOR_H_

#include "geax-front-end/ast/clause/LabelTree.h"

namespace geax {
namespace frontend {

class LabelOr : public LabelTree {
public:
    LabelOr() : LabelTree(AstNodeType::kLabelOr), left_(nullptr), right_(nullptr) {}
    ~LabelOr() = default;

    void setLeft(LabelTree* left) { left_ = left; }
    LabelTree* left() const { return left_; }

    void setRight(LabelTree* right) { right_ = right; }
    LabelTree* right() const { return right_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const LabelTree& other) const override;

    LabelTree* left_;
    LabelTree* right_;
};

inline bool LabelOr::equals(const LabelTree& other) const {
    const auto& LabelTree = static_cast<const LabelOr&>(other);
    bool ret = (nullptr != left_) && (nullptr != LabelTree.left_) && (nullptr != right_) &&
               (nullptr != LabelTree.right_);
    ret = ret && *left_ == *LabelTree.left_ && *right_ == *LabelTree.right_;
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_LABELOR_H_
