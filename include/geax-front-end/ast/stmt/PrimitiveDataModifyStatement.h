/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_PRIMITIVEDATAMODIFYSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_PRIMITIVEDATAMODIFYSTATEMENT_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class PrimitiveDataModifyStatement : public AstNode {
public:
    explicit PrimitiveDataModifyStatement(AstNodeType nodeType) : AstNode(nodeType) {}
    ~PrimitiveDataModifyStatement() = default;
};  // class PrimitiveDataModifyStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_PRIMITIVEDATAMODIFYSTATEMENT_H_
