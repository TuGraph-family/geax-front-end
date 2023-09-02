/**
 * Copyright (c) 2022-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Yaochi <boyao.zby@alibaba-inc.com>
 */

#include <gtest/gtest.h>

#include "GQLParserTest.h"
#include "geax-front-end/utils/Logging.h"

namespace geax {
namespace frontend {

class GQLDMLParserTest : public ::testing::Test {
};

TEST_F(GQLDMLParserTest, base) {
    GQLParserTest parser;
    std::string testPath = "../../../../test/case/dml/";
    ASSERT_EQ(parser.test(testPath), GEAXErrorCode::GEAX_SUCCEED);
}

}  // end of namespace frontend
}  // end of namespace geax
