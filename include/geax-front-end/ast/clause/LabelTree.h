/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_LABELTREE_H_
#define GEAXFRONTEND_AST_CLAUSE_LABELTREE_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class LabelTree : public AstNode {
public:
    explicit LabelTree(AstNodeType type) : AstNode(type) {}
    ~LabelTree() = default;

    friend bool operator==(const LabelTree& lhs, const LabelTree& rhs) {
        return lhs.type() == rhs.type() && lhs.equals(rhs);
    }

protected:
    virtual bool equals(const LabelTree& other) const = 0;
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_LABELTREE_H_
