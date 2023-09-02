/**
 * Copyright (c) 2022-present, Alibaba Inc. All rights reserved.
 *  Author:
 *         Yaochi <boyao.zby@alibaba-inc.com>
 */

#ifndef FRONTEND_ISOGQL_GQLRESOLVECTX_H_
#define FRONTEND_ISOGQL_GQLRESOLVECTX_H_

#include "geax-front-end/isogql/parser/GqlParser.h"
#include "geax-front-end/common/ObjectAllocator.h"

namespace geax {
namespace frontend {

class GQLResolveCtx {
public:
    explicit GQLResolveCtx(geax::common::ObjectArenaAllocator& objAlloc)
        : objAlloc_(objAlloc) {}

    geax::common::ObjectArenaAllocator& objAlloc() { return objAlloc_; }

private:
    geax::common::ObjectArenaAllocator& objAlloc_;
};  // class GQLResolveCtx

}  // namespace frontend
}  // namespace geax

#endif  // FRONTEND_ISOGQL_GQLRESOLVECTX_H_
