/* Copyright (C) 2021 ElectronRock - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/ElectronRock/etherium-chat
 */

#pragma once

#include <grpc++/channel.h>
#include "proto/message_server.grpc.pb.h"
#include "common/foundation.h"
#include <string>
#include <thread>

namespace net {

    class client final  {
    public:
        client(std::shared_ptr<grpc::Channel> message_service_channel, unsigned client_id);

        ~client() = default;

        void polling_task();

        std::string read_message();
        bool send_message(std::string message_text);

        void run();


    private:
        unsigned register_client(unsigned prefered_id);

        std::thread m_polling_thread;
        std::mutex m_polling_mutex;
        std::unique_ptr<message_server_api::storage::Stub> m_message_service;
        unsigned m_id;
        unsigned m_last_polled_id = 0;
        bool isActive = true;
    };

}
