/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_READCONSISTENCY_H_
#define GEAXFRONTEND_AST_CLAUSE_READCONSISTENCY_H_

#include "geax-front-end/ast/clause/Hint.h"

namespace geax {
namespace frontend {

class ReadConsistency : public Hint {
public:
    ReadConsistency() : Hint(AstNodeType::kReadConsistency) {}
    ~ReadConsistency() = default;

    void setVal(std::string&& val) { val_ = std::move(val); }
    const std::string& val() const { return val_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    std::string val_;
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_READCONSISTENCY_H_
