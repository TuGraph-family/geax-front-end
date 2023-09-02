/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_HINT_H_
#define GEAXFRONTEND_AST_CLAUSE_HINT_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class Hint : public AstNode {
public:
    explicit Hint(AstNodeType type) : AstNode(type) {}
    ~Hint() = default;
};  // class Hint

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_HINT_H_
