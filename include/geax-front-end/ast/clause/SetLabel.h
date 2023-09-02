/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_SETLABEL_H_
#define GEAXFRONTEND_AST_CLAUSE_SETLABEL_H_

#include "geax-front-end/ast/clause/LabelTree.h"
#include "geax-front-end/ast/clause/SetItem.h"

namespace geax {
namespace frontend {

class SetLabel : public SetItem {
public:
    SetLabel() : SetItem(AstNodeType::kSetLabel), label_(nullptr) {}
    ~SetLabel() = default;

    void setV(std::string&& v) { v_ = std::move(v); }
    const std::string& v() const { return v_; }

    void setLabel(LabelTree* label) { label_ = label; }
    LabelTree* label() const { return label_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    std::string v_;
    LabelTree* label_;
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_SETLABEL_H_
