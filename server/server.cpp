#include "server.h"

namespace net {

    struct

    ::grpc::Status server::add_message(::grpc::ServerContext* context,
        const ::message_server_api::add_message_request* request, ::message_server_api::add_message_response* response) {
        if(m_clients.find(request->client_id())!=m_clients.end())
        {
            response->set_message_id(m_storage.size());
            m_storage.emplace_back(request->client_id(), request->text());
            std::cout << "Message received from: " << request->client_id() <<" : " << request->text() << std::endl;
        }
        else
        {
            response->set_message_id(0);
        }
        return grpc::Status::OK;
    }

    ::grpc::Status server::poll_message(::grpc::ServerContext* context,
        const ::message_server_api::poll_message_request* request, ::message_server_api::poll_message_response* response) {
        if(m_storage.size()>request->last_polled_message_id()) {
            for (int i = request->last_polled_message_id()+1; i < m_storage.size(); i++) {
                response->add_client_id(m_storage[i].client_id);
                response->add_message_id(i);
                response->add_text(m_storage[i].msg_text);
            }
        }
        return grpc::Status::OK;
    }

    ::grpc::Status server::register_client(::grpc::ServerContext* context,
        const ::message_server_api::register_client_request* request, ::message_server_api::register_client_response* response) {
        auto id = request->prefered_client_id();
        if (m_clients.find(id)==m_clients.end())
        {
            response->set_client_id(id);
            m_clients.emplace(id);
        }
        else
        {
            auto last = m_clients.end()--;
            auto u_id = (*last)+1;
            response->set_client_id(u_id);
            m_clients.emplace(u_id);
        }
        return grpc::Status::OK;
    }

}