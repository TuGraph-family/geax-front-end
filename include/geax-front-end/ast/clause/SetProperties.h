/**
 * Copyright (c) 2022-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_SETPROPERTIES_H_
#define GEAXFRONTEND_AST_CLAUSE_SETPROPERTIES_H_

#include "geax-front-end/ast/clause/PropStruct.h"
#include "geax-front-end/ast/clause/SetItem.h"

namespace geax {
namespace frontend {

class SetProperties : public SetItem {
public:
    SetProperties() : SetItem(AstNodeType::kSetProperties), structs_(nullptr) {}
    ~SetProperties() = default;

    void setV(std::string&& v) { v_ = std::move(v); }
    const std::string& v() const { return v_; }

    void setStructs(PropStruct* structs) { structs_ = structs; }
    PropStruct* structs() const { return structs_; }

    std::any accept(AstNodeVisitor& visitor) override {
        return visitor.visit(this);
    }

    DEFINE_FROM_AND_TO_JSON

private:
    DECLARE_JSON_FIELDS() {
        JSON_FIELD(type);
        JSON_FIELD(v);
        JSON_FIELD(structs);
    }

    std::string  v_;
    PropStruct*  structs_;
};

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_SETPROPERTIES_H_
