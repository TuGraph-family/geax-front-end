/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_SINGLELABEL_H_
#define GEAXFRONTEND_AST_CLAUSE_SINGLELABEL_H_

#include "geax-front-end/ast/clause/LabelTree.h"

namespace geax {
namespace frontend {

class SingleLabel : public LabelTree {
public:
    SingleLabel() : LabelTree(AstNodeType::kSingleLabel) {}
    ~SingleLabel() = default;

    void setLabel(std::string&& label) { label_ = std::move(label); }
    const std::string& label() const { return label_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const LabelTree& other) const override;

    std::string label_;
};

inline bool SingleLabel::equals(const LabelTree& other) const {
    const auto& LabelTree = static_cast<const SingleLabel&>(other);
    bool ret = label_ == LabelTree.label_;
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_SINGLELABEL_H_
