/**
 * Copyright (c) 2022-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Yaochi <boyao.zby@alibaba-inc.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_OTHERWISE_H_
#define GEAXFRONTEND_AST_STMT_OTHERWISE_H_

#include "geax-front-end/ast/stmt/QueryConjunctionType.h"

namespace geax {
namespace frontend {

class OtherWise : public QueryConjunctionType {
public:
    OtherWise() : QueryConjunctionType(AstNodeType::kOtherWise) {}
    ~OtherWise() = default;

    std::any accept(AstNodeVisitor& visitor) override {
        return visitor.visit(this);
    }

    DEFINE_FROM_AND_TO_JSON

private:
    DECLARE_JSON_FIELDS() {
        JSON_FIELD(type);
    }
};  // class OtherWise

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_OTHERWISE_H_
