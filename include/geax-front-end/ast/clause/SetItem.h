/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_SETITEM_H_
#define GEAXFRONTEND_AST_CLAUSE_SETITEM_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class SetItem : public AstNode {
public:
    explicit SetItem(AstNodeType type) : AstNode(type) {}
    ~SetItem() = default;
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_SETITEM_H_
