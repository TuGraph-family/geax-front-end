/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_BINDINGGRAPH_H_
#define GEAXFRONTEND_AST_CLAUSE_BINDINGGRAPH_H_

#include "geax-front-end/ast/clause/BindingVar.h"

namespace geax {
namespace frontend {

class BindingGraph : public BindingVar {
public:
    BindingGraph() : BindingVar(AstNodeType::kBindingGraph) {}
    ~BindingGraph() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BindingGraph

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_BINDINGGRAPH_H_
