/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_OPCONCURRENT_H_
#define GEAXFRONTEND_AST_CLAUSE_OPCONCURRENT_H_

#include "geax-front-end/ast/clause/Hint.h"

namespace geax {
namespace frontend {

class OpConcurrent : public Hint {
public:
    OpConcurrent() : Hint(AstNodeType::kOpConcurrent) {}
    ~OpConcurrent() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_OPCONCURRENT_H_
