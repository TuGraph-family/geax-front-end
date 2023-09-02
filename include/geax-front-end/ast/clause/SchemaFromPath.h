/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_CLAUSE_SCHEMAFROMPATH_H_
#define GEAXFRONTEND_AST_CLAUSE_SCHEMAFROMPATH_H_

#include "geax-front-end/ast/clause/SchemaRef.h"

namespace geax {
namespace frontend {

class SchemaFromPath : public SchemaRef {
public:
    SchemaFromPath() : SchemaRef(AstNodeType::kSchemaFromPath) {}
    ~SchemaFromPath() = default;

    void setPath(std::string&& path) { path_ = std::move(path); }
    const std::string& path() const { return path_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    std::string path_;
};  // class SchemaFromPath

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_CLAUSE_SCHEMAFROMPATH_H_
