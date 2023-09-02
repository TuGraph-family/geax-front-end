/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_JOINQUERYEXPRESSION_H_
#define GEAXFRONTEND_AST_STMT_JOINQUERYEXPRESSION_H_

#include "geax-front-end/ast/AstNode.h"
#include "geax-front-end/ast/stmt/CompositeQueryStatement.h"
#include "geax-front-end/ast/stmt/JoinRightPart.h"

namespace geax {
namespace frontend {

class JoinQueryExpression : public AstNode {
public:
    JoinQueryExpression() : AstNode(AstNodeType::kJoinQuery), head_(nullptr) {}
    ~JoinQueryExpression() = default;

    void setHead(CompositeQueryStatement* head) { head_ = head; }
    CompositeQueryStatement* head() const { return head_; }

    void appendBody(JoinRightPart* part, std::optional<PrimitiveResultStatement*>&& result) {
        body_.emplace_back(part, std::move(result));
    }
    void setBody(
        std::vector<std::tuple<JoinRightPart*, std::optional<PrimitiveResultStatement*>>>&&
            body) {
        body_ = std::move(body);
    }
    const auto& body() const { return body_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    CompositeQueryStatement* head_;
    std::vector<std::tuple<JoinRightPart*, std::optional<PrimitiveResultStatement*>>> body_;
};  // class JoinQueryExpression

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_JOINQUERYEXPRESSION_H_
