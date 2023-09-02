/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_EXPR_EXPR_H_
#define GEAXFRONTEND_AST_EXPR_EXPR_H_

#include "geax-front-end/ast/AstNode.h"

namespace geax {
namespace frontend {

class GQLExpr;

/**
 * An Expr stands for an expression node.
 */
class Expr : public AstNode {
public:
    explicit Expr(AstNodeType type) : AstNode(type) {}
    ~Expr() = default;

    friend bool operator==(const Expr& lhs, const Expr& rhs) {
        return lhs.type() == rhs.type() && lhs.equals(rhs);
    }

protected:
    virtual bool equals(const Expr& other) const = 0;

    // Representation of expressions in json could be various, one solution is
    // like Lisp's 'S-expression'
    // (https://stackoverflow.com/questions/20737045/representing-logic-as-data-in-json)
    //
    // But we employ another here:
    // Say we have an expression (a and b) or c, and we express it in json like
    //
    // {
    //  "type": "OR",
    //  "left": {
    //          "type": "IntegerLiteral"
    //          "IntegerLiteral": c
    //  },
    //  "right": {
    //          "type": "AND",
    //          "left": {
    //                  "type": "StringLiteral",
    //                  "val": "a"
    //          },
    //          "right": {
    //                  "type": "BoolLiteral",
    //                  "val": true
    //          }
    //      }
    // }
    //
    // I think this is expressive and easy to parse, and let's see if this format is good enough.
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_EXPR_EXPR_H_
