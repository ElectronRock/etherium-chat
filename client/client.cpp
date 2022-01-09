#include "client.h"

namespace net {

    client::client(
            std::shared_ptr<grpc::Channel> message_service_channel)
        : m_message_service(message_server_api::storage::NewStub(message_service_channel)) {

    }

    void client::run() {

    }

}