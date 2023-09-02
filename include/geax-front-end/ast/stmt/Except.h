/**
 * Copyright (c) 2022-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Yaochi <boyao.zby@alibaba-inc.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_EXCEPT_H_
#define GEAXFRONTEND_AST_STMT_EXCEPT_H_

#include "geax-front-end/ast/stmt/QueryConjunctionType.h"

namespace geax {
namespace frontend {

class Except : public QueryConjunctionType {
public:
    Except()
        : QueryConjunctionType(AstNodeType::kExcept),
          isDistinct_(true) {}
    ~Except() = default;

    void setDistince(const bool& isDistinct) { isDistinct_ = isDistinct; }
    const bool distinct() const { return isDistinct_; }

    std::any accept(AstNodeVisitor& visitor) override {
        return visitor.visit(this);
    }

    DEFINE_FROM_AND_TO_JSON

private:
    DECLARE_JSON_FIELDS() {
        JSON_FIELD(type);
        JSON_FIELD(isDistinct);
    }

    bool isDistinct_;
};  // class Except

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_EXCEPT_H_
