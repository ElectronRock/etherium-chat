#include "client.h"
#include <chrono>
#include <utility>

namespace net {

    client::client(
            std::shared_ptr<grpc::Channel> message_service_channel,
            unsigned client_id)
        : m_message_service(message_server_api::storage::NewStub(message_service_channel))
        , m_id(client_id){

    }

    void client::run() {
        register_client(m_id);
        m_polling_thread = std::thread (
                [this]{ polling_task(); }
                );
        for (;;) {
            auto&& message_text = read_message();
            if(!message_text.empty())
                send_message(message_text);
            else
                break;
        }
    }

    void client::polling_task() {
        while(isActive) {

            message_server_api::poll_message_request poll_message_request;
            poll_message_request.set_last_polled_message_id(m_last_polled_id);
            grpc::ClientContext poll_message_context;
            message_server_api::poll_message_response poll_message_response;
            m_polling_mutex.lock();
            auto&& status =
                    m_message_service->poll_message(&poll_message_context,
                                                   poll_message_request,
                                                   &poll_message_response);
            m_polling_mutex.unlock();

            auto size = poll_message_response.text().size();
            for(int i = 0; i < size; i++) {
                std::cout << poll_message_response.client_id()[i];
                std::cout << poll_message_response.text()[i];
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    std::string client::read_message() {
        std::string message_text;
        std::getline(std::cin, message_text);
        return message_text;
        }

    bool client::send_message(std::string message_text) {

        message_server_api::add_message_request add_message_request;
        add_message_request.set_client_id(m_id);
        add_message_request.set_text(message_text);
        grpc::ClientContext add_message_context;
        message_server_api::add_message_response add_message_response;
        m_polling_mutex.lock();
        auto&& status =
                m_message_service->add_message(&add_message_context,
                                               add_message_request,
                                               &add_message_response);
        m_polling_mutex.unlock();

        return status.ok();
    }


    unsigned client::register_client(unsigned prefered_id) {
        message_server_api::register_client_request request;
        request.set_prefered_client_id(prefered_id);
        grpc::ClientContext context;
        message_server_api::register_client_response response;
        auto&& status = m_message_service->register_client(&context, request, &response);
        return status.ok() ? response.client_id() : 0;
    }


}