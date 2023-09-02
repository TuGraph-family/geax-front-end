/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_OTHERWISE_H_
#define GEAXFRONTEND_AST_CLAUSE_OTHERWISE_H_

#include "geax-front-end/ast/clause/QueryConjunctionType.h"

namespace geax {
namespace frontend {

class OtherWise : public QueryConjunctionType {
public:
    OtherWise() : QueryConjunctionType(AstNodeType::kOtherWise) {}
    ~OtherWise() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class OtherWise

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_OTHERWISE_H_
