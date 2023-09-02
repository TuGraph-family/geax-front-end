/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_TUPLEGET_H_
#define GEAXFRONTEND_AST_EXPR_TUPLEGET_H_

#include "geax-front-end/ast/expr/UnaryOp.h"

namespace geax {
namespace frontend {

class TupleGet : public UnaryOp {
public:
    TupleGet() : UnaryOp(AstNodeType::kTupleGet) {}
    ~TupleGet() = default;

    void setIndex(int64_t index) { index_ = index; }
    int64_t index() const { return index_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    int64_t index_;
};  // class TupleGet

inline bool TupleGet::equals(const Expr& other) const {
    const auto& expr = static_cast<const TupleGet&>(other);
    bool ret = UnaryOp::equals(other) && index_ == expr.index_;
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_TUPLEGET_H_
