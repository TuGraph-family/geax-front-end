/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_ISLABELED_H_
#define GEAXFRONTEND_AST_EXPR_ISLABELED_H_

#include "geax-front-end/ast/clause/LabelTree.h"
#include "geax-front-end/ast/expr/UnaryOp.h"

namespace geax {
namespace frontend {

class IsLabeled : public UnaryOp {
public:
    IsLabeled() : UnaryOp(AstNodeType::kIsLabeled), labelTree_(nullptr) {}
    ~IsLabeled() = default;

    void setLabelTree(LabelTree* labelTree) { labelTree_ = labelTree; }
    LabelTree* labelTree() const { return labelTree_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    LabelTree* labelTree_;
};  // class IsLabeled

inline bool IsLabeled::equals(const Expr& other) const {
    const auto& expr = static_cast<const IsLabeled&>(other);
    bool ret = UnaryOp::equals(other) && (nullptr != labelTree_) && (nullptr != expr.labelTree_) &&
               *labelTree_ == *expr.labelTree_;
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_ISLABELED_H_
