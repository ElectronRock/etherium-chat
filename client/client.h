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
        client(std::shared_ptr<grpc::Channel> message_service_channel, std::string client_id);

        ~client() = default;
        void run();

    private:
        void polling_task();
        bool send_message(std::string message_text);
        std::string register_client(const std::string& prefered_id);
        std::string read_message();

        std::thread m_polling_thread;
        std::mutex m_polling_mutex;
        std::unique_ptr<message_server_api::storage::Stub> m_message_service;
        std::string m_id;
        unsigned m_last_polled_id = 0;
        bool isActive = true;
    };

}
