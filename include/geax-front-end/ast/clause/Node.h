/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_Node_H_
#define GEAXFRONTEND_AST_CLAUSE_Node_H_

#include "geax-front-end/ast/AstNode.h"
#include "geax-front-end/ast/clause/ElementFiller.h"

namespace geax {
namespace frontend {

/**
 * An Node stands for a vertex pattern in the ast tree.
 */
class Node : public AstNode {
public:
    Node() : AstNode(AstNodeType::kNode), filler_(nullptr) {}
    ~Node() = default;

    void setFiller(ElementFiller* filler) { filler_ = filler; }
    ElementFiller* filler() const { return filler_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    ElementFiller* filler_;
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_Node_H_
