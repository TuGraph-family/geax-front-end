/**
 * Copyright 2023 AntGroup CO., Ltd.
 */

#ifndef FRONTEND_UTILS_CONV_H_
#define FRONTEND_UTILS_CONV_H_

namespace geax {
namespace utils {

template <typename B, typename D>
bool checkedCast(B* b, D*& d) {
    static_assert(std::is_base_of<B, D>::value, "type `B` must be the base of type `D`");
    d = dynamic_cast<D*>(b);
    return d != nullptr;
}

template <typename B, typename D>
bool uncheckedCast(B* b, D*& d) {
    static_assert(std::is_base_of<B, D>::value, "type `B` must be the base of type `D`");
    d = static_cast<D*>(b);
    return d != nullptr;
}

}  // namespace utils
}  // namespace geax

#endif  // FRONTEND_UTILS_CONV_H_
