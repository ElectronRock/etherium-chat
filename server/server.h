/* Copyright (C) 2021 ElectronRock - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/ElectronRock/etherium-chat
 */

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
    };

}