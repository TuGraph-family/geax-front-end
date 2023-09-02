/**
 * Copyright 2023 AntGroup CO., Ltd.
 */

#ifndef GEAXFRONTEND_GEAXERRORCODE_H_
#define GEAXFRONTEND_GEAXERRORCODE_H_

#include <cstdint>
#include <string>

namespace geax {
namespace frontend {

enum class GEAXErrorCode : uint32_t {
    GEAX_SUCCEED                         = 0,
    GEAX_ERROR                           = 1,
    GEAX_OOPS                            = 4,

    GEAX_COMMON_INVALID_ARGUMENT         = 30002,
    GEAX_COMMON_NULLPTR                  = 30003,
    GEAX_COMMON_NOT_SUPPORT              = 30005,
    GEAX_COMMON_PARSE_ERROR              = 30006,
    GEAX_COMMON_KEY_NOT_FOUND            = 30016,
    GEAX_COMMON_SYNTAX_ERROR             = 30019,
};

#define GEAX_OK(ret)    (GEAXErrorCode::GEAX_SUCCEED == (ret))
#define GEAX_FAIL(ret)  (GEAXErrorCode::GEAX_SUCCEED != (ret))

#define GEAX_ANY_OK(ret)    (GEAXErrorCode::GEAX_SUCCEED == (std::any_cast<GEAXErrorCode>(ret)))
#define GEAX_ANY_FAIL(ret)  (GEAXErrorCode::GEAX_SUCCEED != (std::any_cast<GEAXErrorCode>(ret)))

#define GEAX_RET_OK(statement)    (GEAXErrorCode::GEAX_SUCCEED == (ret=(statement)))
#define GEAX_RET_FAIL(statement)  (GEAXErrorCode::GEAX_SUCCEED != (ret=(statement)))

#define GEAX_ANY_RET_OK(statement) \
(GEAXErrorCode::GEAX_SUCCEED == (ret=(std::any_cast<GEAXErrorCode>(statement))))

#define GEAX_ANY_RET_FAIL(statement) \
(GEAXErrorCode::GEAX_SUCCEED != (ret=(std::any_cast<GEAXErrorCode>(statement))))

const std::string& ToString(const GEAXErrorCode code);

}  // namespace frontend
}  // namespace geax

#endif  // GEAXFRONTEND_GEAXERRORCODE_H_
