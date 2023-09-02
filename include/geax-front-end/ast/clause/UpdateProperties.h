/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_UPDATEPROPERTIES_H_
#define GEAXFRONTEND_AST_CLAUSE_UPDATEPROPERTIES_H_

#include "geax-front-end/ast/clause/PropStruct.h"
#include "geax-front-end/ast/clause/SetItem.h"

namespace geax {
namespace frontend {

class UpdateProperties : public SetItem {
public:
    UpdateProperties() : SetItem(AstNodeType::kUpdateProperties), structs_(nullptr) {}
    ~UpdateProperties() = default;

    void setV(std::string&& v) { v_ = std::move(v); }
    const std::string& v() const { return v_; }

    void setStructs(PropStruct* structs) { structs_ = structs; }
    PropStruct* structs() const { return structs_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    std::string v_;
    PropStruct* structs_;
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_UPDATEPROPERTIES_H_
