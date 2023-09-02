/**
 * Copyright (c) 2023-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         lili <liangjingru.ljr@antgroup.com>
 */

#ifndef GEAXFRONTEND_AST_STMT_MATCHSTATEMENT_H_
#define GEAXFRONTEND_AST_STMT_MATCHSTATEMENT_H_

#include "geax-front-end/ast/clause/GraphPattern.h"
#include "geax-front-end/ast/stmt/SimpleQueryStatement.h"

namespace geax {
namespace frontend {

enum class StatementMode : uint8_t {
    kOptional,
    kMandatory,
    kMax,
};

inline const char* ToString(StatementMode mode) {
    static const StrArray<enumNum(StatementMode::kMax)> kNameMap = {
        "optional",
        "mandatory",
    };
    const auto idx = static_cast<size_t>(mode);
    return idx < kNameMap.size() ? kNameMap[idx] : geax::frontend::kUnknown;
}

inline bool ToEnum(std::string_view sv, StatementMode& mode) {
    static const std::unordered_map<std::string_view, StatementMode> kTypeMap = {
        {"optional", StatementMode::kOptional},
        {"mandatory", StatementMode::kMandatory},
    };
    auto it = kTypeMap.find(sv);
    return it == kTypeMap.end() ? false : (mode = it->second, true);
}

class MatchStatement : public SimpleQueryStatement {
public:
    MatchStatement()
        : SimpleQueryStatement(AstNodeType::kMatchStatement), graphPattern_(nullptr) {}
    ~MatchStatement() = default;

    void setGraphPattern(GraphPattern* graphPattern) { graphPattern_ = graphPattern; }
    GraphPattern* graphPattern() const { return graphPattern_; }

    void setStatementMode(StatementMode mode) { statementMode_ = mode; }
    const std::optional<StatementMode>& statementMode() const { return statementMode_; }

    std::any accept(AstNodeVisitor& visitor) override { return visitor.visit(this); }

private:
    GraphPattern* graphPattern_;
    std::optional<StatementMode> statementMode_;
};  // MatchStatement

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_AST_STMT_MATCHSTATEMENT_H_
