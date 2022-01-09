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

}