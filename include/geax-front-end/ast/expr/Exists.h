/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_EXISTS_H_
#define GEAXFRONTEND_AST_EXPR_EXISTS_H_

#include "geax-front-end/ast/clause/PathChain.h"
#include "geax-front-end/ast/expr/UnaryOp.h"

namespace geax {
namespace frontend {

class Exists : public UnaryOp {
public:
    Exists() : UnaryOp(AstNodeType::kExists) {}
    ~Exists() = default;

    void appendPathChain(PathChain* pathChain) { pathChains_.emplace_back(pathChain); }
    void setPathChains(std::vector<PathChain*>&& pathChains) {
        pathChains_ = std::move(pathChains);
    }
    const std::vector<PathChain*>& pathChains() const { return pathChains_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    bool equals(const Expr& other) const override;

    std::vector<PathChain*> pathChains_;
};  // class Exists

inline bool Exists::equals(const Expr& other) const {
    const auto& expr = static_cast<const Exists&>(other);
    // TODO(ljr): PathChain equals
    bool ret = UnaryOp::equals(other) && pathChains_.size() == expr.pathChains_.size();
    return ret;
}

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_EXISTS_H_
