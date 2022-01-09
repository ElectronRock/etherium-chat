#include "server.h"

namespace net {

    ::grpc::Status server::add_message(::grpc::ServerContext* context,
        const ::message_server_api::add_message_request* request, ::message_server_api::add_message_response* response) {

        return grpc::Status::OK;
    }

    ::grpc::Status server::poll_message(::grpc::ServerContext* context,
        const ::message_server_api::poll_message_request* request, ::message_server_api::poll_message_response* response) {

        return grpc::Status::OK;
    }

    ::grpc::Status server::register_client(::grpc::ServerContext* context,
        const ::message_server_api::register_client_request* request, ::message_server_api::register_client_response* response) {

        return grpc::Status::OK;
    }

}