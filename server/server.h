/* Copyright (C) 2021 ElectronRock - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/ElectronRock/etherium-chat
 */

#pragma once
#include <unordered_map>
#include <unordered_set>
#include "proto/message_server.grpc.pb.h"

namespace net {

    class server final : public message_server_api::storage::Service {
    public:
      virtual ~server() override = default;

        virtual ::grpc::Status add_message(::grpc::ServerContext* context, 
            const ::message_server_api::add_message_request* request, ::message_server_api::add_message_response* response) override;

        virtual ::grpc::Status poll_message(::grpc::ServerContext* context, 
            const ::message_server_api::poll_message_request* request, ::message_server_api::poll_message_response* response) override;

        virtual ::grpc::Status register_client(::grpc::ServerContext* context, 
            const ::message_server_api::register_client_request* request, ::message_server_api::register_client_response* response) override;
    private:

        struct message final {
            message(unsigned int u = 0u, std::string&& s = "")
              : client_id(u), msg_text(std::move(s)) {}
            unsigned int client_id;
            std::string msg_text;
        };

        std::string generate_id(const std::string& prefered_id);
        std::vector<message> m_storage;
        std::unordered_map<unsigned, std::string> m_clients;
        std::unordered_set<std::string> m_clientSet;
    };

}