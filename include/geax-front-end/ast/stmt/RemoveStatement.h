/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_REMOVESTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_REMOVESTATEMENT_H_

#include "geax-front-end/ast/stmt/PrimitiveDataModifyStatement.h"

namespace geax {
namespace frontend {

class RemoveStatement : public PrimitiveDataModifyStatement {
public:
    RemoveStatement() : PrimitiveDataModifyStatement(AstNodeType::kRemoveStatement) {}
    ~RemoveStatement() = default;

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }
};  // class RemoveStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_REMOVESTATEMENT_H_
