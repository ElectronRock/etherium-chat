/*
 * Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 */

#pragma once

#include <grpc++/channel.h>

#include "common/foundation.h"

namespace net {

    class client final  {
    public:
        client(std::shared_ptr<grpc::Channel> message_service_channel);

        ~client() = default;

    private:

    };

}
