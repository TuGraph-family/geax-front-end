/**
 * Copyright (c) 2022-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Yaochi <boyao.zby@alibaba-inc.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_SCHEMAFROMPATH_H_
#define GEAXFRONTEND_AST_STMT_SCHEMAFROMPATH_H_

#include "geax-front-end/ast/stmt/SchemaRef.h"

namespace geax {
namespace frontend {

class SchemaFromPath : public SchemaRef {
public:
    SchemaFromPath() : SchemaRef(AstNodeType::kSchemaFromPath) {}
    ~SchemaFromPath() = default;

    void setPath(std::string&& path) { path_ = std::move(path); }
    const std::string& path() const { return path_; }

    std::any accept(AstNodeVisitor& visitor) override {
        return visitor.visit(this);
    }

    DEFINE_FROM_AND_TO_JSON

private:
    DECLARE_JSON_FIELDS() {
        JSON_FIELD(type);
        JSON_FIELD(path);
    }

    std::string path_;
};  // class SchemaFromPath

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_SCHEMAFROMPATH_H_
