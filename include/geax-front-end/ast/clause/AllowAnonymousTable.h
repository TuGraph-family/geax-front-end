/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_ALLOWANONYMOUSTABLE_H_
#define GEAXFRONTEND_AST_CLAUSE_ALLOWANONYMOUSTABLE_H_

#include "geax-front-end/ast/clause/Hint.h"
#include "geax-front-end/ast/expr/Param.h"

namespace geax {
namespace frontend {

class AllowAnonymousTable : public Hint {
public:
    AllowAnonymousTable() : Hint(AstNodeType::kAllowAnonymousTable) {}
    ~AllowAnonymousTable() = default;

    void setVal(BoolParam&& val) { val_ = std::move(val); }
    const BoolParam val() const { return val_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    BoolParam val_;
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_ALLOWANONYMOUSTABLE_H_
