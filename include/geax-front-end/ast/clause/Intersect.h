/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_INTERSECT_H_
#define GEAXFRONTEND_AST_CLAUSE_INTERSECT_H_

#include "geax-front-end/ast/clause/QueryConjunctionType.h"

namespace geax {
namespace frontend {

class Intersect : public QueryConjunctionType {
public:
    Intersect() : QueryConjunctionType(AstNodeType::kIntersect), isDistinct_(true) {}
    ~Intersect() = default;

    void setDistinct(bool isDistinct) { isDistinct_ = isDistinct; }
    bool distinct() const { return isDistinct_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool isDistinct_;
};  // class Intersect

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_INTERSECT_H_
