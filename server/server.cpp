#include "server.h"
#include <random>

namespace net {

    ::grpc::Status server::add_message(::grpc::ServerContext* context,
        const ::message_server_api::add_message_request* request, ::message_server_api::add_message_response* response) {
        if(m_clients.find(request->client_id()) != m_clients.end()) {
            response->set_message_id(m_storage.size());
            m_storage.emplace_back(request->client_id(), request->text());
            std::cout << "Message received from: " << request->client_id() <<" : " << request->text() << std::endl;
        } else {
            response->set_message_id(0);
        }
        return grpc::Status::OK;
    }

    ::grpc::Status server::poll_message(::grpc::ServerContext* context,
        const ::message_server_api::poll_message_request* request, ::message_server_api::poll_message_response* response) {
        if(m_storage.size()>request->last_polled_message_id()) {
            for (int i = request->last_polled_message_id() + 1; i < m_storage.size(); i++) {
                if(request->client_id() != m_storage[i].client_id) {
                    response->add_client_id(m_storage[i].client_id);
                    response->add_message_id(i);
                    response->add_text(m_storage[i].msg_text);
                }
            }
        }
        return grpc::Status::OK;
    }

    ::grpc::Status server::register_client(::grpc::ServerContext* context,
        const ::message_server_api::register_client_request* request, ::message_server_api::register_client_response* response) {
        auto&& id = request->prefered_client_id();
        auto&& unique_id = generate_id(id);
        response->set_client_id(unique_id);
        m_clients.emplace(std::move(unique_id));
        return grpc::Status::OK;
    }

    std::string server::generate_id(const std::string& preferred_id) const {
        if (m_clients.count(preferred_id) == 0) 
            return preferred_id;

        std::string res = preferred_id;
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution uni(0, 1337); 
        for (;;) {
            const auto random_integer = uni(rng);
            auto&& asStr = std::to_string(random_integer);
            if (m_clients.count(res + asStr) == 0) {
                res += asStr;
                break;
            }
        }
        return res;
    }
}
