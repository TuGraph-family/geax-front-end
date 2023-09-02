/**
 * Copyright 2023 AntGroup CO., Ltd.
 */

#include "geax-front-end/GEAXErrorCode.h"
#include <unordered_map>

namespace geax {
namespace frontend {

const std::string& ToString(const GEAXErrorCode code) {
    static const std::string ret = "UNKNOWN_ERROR_CODE";

    static std::unordered_map<GEAXErrorCode, std::string> dict = {
        {GEAXErrorCode::GEAX_SUCCEED, "GEAX_SUCCEED"},
        {GEAXErrorCode::GEAX_ERROR, "GEAX_ERROR"},
        {GEAXErrorCode::GEAX_OOPS, "GEAX_OOPS"},
        {GEAXErrorCode::GEAX_COMMON_INVALID_ARGUMENT, "GEAX_COMMON_INVALID_ARGUMENT"},
        {GEAXErrorCode::GEAX_COMMON_NULLPTR, "GEAX_COMMON_NULLPTR"},
        {GEAXErrorCode::GEAX_COMMON_NOT_SUPPORT, "GEAX_COMMON_NOT_SUPPORT"},
        {GEAXErrorCode::GEAX_COMMON_PARSE_ERROR, "GEAX_COMMON_PARSE_ERROR"},
        {GEAXErrorCode::GEAX_COMMON_KEY_NOT_FOUND, "GEAX_COMMON_KEY_NOT_FOUND"},
        {GEAXErrorCode::GEAX_COMMON_SYNTAX_ERROR, "GEAX_COMMON_SYNTAX_ERROR"},
    };

    auto it = dict.find(code);
    if (it != dict.end()) {
        return it->second;
    }
    return ret;
}

}  // namespace frontend
}  // namespace geax
