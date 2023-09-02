/**
 * Copyright (c) 2022-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         suosi.zl <suosi.zl@alibaba-inc.com>
 */

#ifndef FRONTEND_ISOGQL_PARSER_ANTLRGQLPARSER_H_
#define FRONTEND_ISOGQL_PARSER_ANTLRGQLPARSER_H_

#include "BaseErrorListener.h"
#include "geax-front-end/isogql/parser/GqlLexer.h"
#include "geax-front-end/isogql/parser/GqlParser.h"

namespace geax {
namespace frontend {

class AntlrGqlParser : public antlr4::BaseErrorListener {
public:
    explicit AntlrGqlParser(const std::string& query)
        : query_(query),
          input_(query_),
          lexer_(&input_),
          tokens_(&lexer_),
          parser_(&tokens_),
          rule_(nullptr) {}

    parser::GqlParser::GqlRequestContext* gqlRequest() {
        if (!tryParseBySLLMode() && !tryParseByLLMode()) {
            rule_ = nullptr;
        }
        return rule_;
    }

    antlr4::ANTLRInputStream& input() { return input_; }

    parser::GqlLexer& lexer() { return lexer_; }

    const std::string& query() { return query_; }

    std::string& error() { return errorMsg_; }

private:
    bool tryParseBySLLMode();

    bool tryParseByLLMode();
    /**
     * {@inheritDoc}
     *
     * <p>
     * This implementation prints messages to {@link System#err} containing the
     * values of {@code line}, {@code charPositionInLine}, and {@code msg} using
     * the following format.</p>
     *
     * <pre>
     * line <em>line</em>:<em>charPositionInLine</em> <em>msg</em>
     * </pre>
     */
    void syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line,
                     size_t charPositionInLine, const std::string& msg,
                     std::exception_ptr e) override;

private:
    const std::string& query_;
    antlr4::ANTLRInputStream input_;
    parser::GqlLexer lexer_;
    antlr4::CommonTokenStream tokens_;
    parser::GqlParser parser_;
    std::string errorMsg_;
    parser::GqlParser::GqlRequestContext* rule_;
};

}  // namespace frontend
}  // namespace geax

#endif  // FRONTEND_ISOGQL_PARSER_ANTLRGQLPARSER_H_
