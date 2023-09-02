/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_BINDINGTABLE_H_
#define GEAXFRONTEND_AST_CLAUSE_BINDINGTABLE_H_

#include "geax-front-end/ast/clause/BindingVar.h"

namespace geax {
namespace frontend {

class BindingTable : public BindingVar {
public:
    BindingTable() : BindingVar(AstNodeType::kBindingTable) {}
    ~BindingTable() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class BindingTable

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_BINDINGTABLE_H_
