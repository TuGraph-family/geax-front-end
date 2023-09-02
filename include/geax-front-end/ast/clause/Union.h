/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_UNION_H_
#define GEAXFRONTEND_AST_CLAUSE_UNION_H_

#include "geax-front-end/ast/clause/QueryConjunctionType.h"

namespace geax {
namespace frontend {

class Union : public QueryConjunctionType {
public:
    Union() : QueryConjunctionType(AstNodeType::kUnion), isDistinct_(true) {}
    ~Union() = default;

    void setDistinct(bool isDistinct) { isDistinct_ = isDistinct; }
    bool distinct() const { return isDistinct_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool isDistinct_;
};  // class Union

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_UNION_H_
