// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: message_server.proto

#include "message_server.pb.h"
#include "message_server.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace message_server_api {

static const char* storage_method_names[] = {
  "/message_server_api.storage/add_message",
  "/message_server_api.storage/poll_message",
};

std::unique_ptr< storage::Stub> storage::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< storage::Stub> stub(new storage::Stub(channel, options));
  return stub;
}

storage::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_add_message_(storage_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_poll_message_(storage_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status storage::Stub::add_message(::grpc::ClientContext* context, const ::message_server_api::add_message_request& request, ::message_server_api::add_message_response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::message_server_api::add_message_request, ::message_server_api::add_message_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_add_message_, context, request, response);
}

void storage::Stub::async::add_message(::grpc::ClientContext* context, const ::message_server_api::add_message_request* request, ::message_server_api::add_message_response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::message_server_api::add_message_request, ::message_server_api::add_message_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_add_message_, context, request, response, std::move(f));
}

void storage::Stub::async::add_message(::grpc::ClientContext* context, const ::message_server_api::add_message_request* request, ::message_server_api::add_message_response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_add_message_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::message_server_api::add_message_response>* storage::Stub::PrepareAsyncadd_messageRaw(::grpc::ClientContext* context, const ::message_server_api::add_message_request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::message_server_api::add_message_response, ::message_server_api::add_message_request, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_add_message_, context, request);
}

::grpc::ClientAsyncResponseReader< ::message_server_api::add_message_response>* storage::Stub::Asyncadd_messageRaw(::grpc::ClientContext* context, const ::message_server_api::add_message_request& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncadd_messageRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status storage::Stub::poll_message(::grpc::ClientContext* context, const ::message_server_api::poll_message_request& request, ::message_server_api::poll_message_response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::message_server_api::poll_message_request, ::message_server_api::poll_message_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_poll_message_, context, request, response);
}

void storage::Stub::async::poll_message(::grpc::ClientContext* context, const ::message_server_api::poll_message_request* request, ::message_server_api::poll_message_response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::message_server_api::poll_message_request, ::message_server_api::poll_message_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_poll_message_, context, request, response, std::move(f));
}

void storage::Stub::async::poll_message(::grpc::ClientContext* context, const ::message_server_api::poll_message_request* request, ::message_server_api::poll_message_response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_poll_message_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::message_server_api::poll_message_response>* storage::Stub::PrepareAsyncpoll_messageRaw(::grpc::ClientContext* context, const ::message_server_api::poll_message_request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::message_server_api::poll_message_response, ::message_server_api::poll_message_request, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_poll_message_, context, request);
}

::grpc::ClientAsyncResponseReader< ::message_server_api::poll_message_response>* storage::Stub::Asyncpoll_messageRaw(::grpc::ClientContext* context, const ::message_server_api::poll_message_request& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncpoll_messageRaw(context, request, cq);
  result->StartCall();
  return result;
}

storage::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      storage_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< storage::Service, ::message_server_api::add_message_request, ::message_server_api::add_message_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](storage::Service* service,
             ::grpc::ServerContext* ctx,
             const ::message_server_api::add_message_request* req,
             ::message_server_api::add_message_response* resp) {
               return service->add_message(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      storage_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< storage::Service, ::message_server_api::poll_message_request, ::message_server_api::poll_message_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](storage::Service* service,
             ::grpc::ServerContext* ctx,
             const ::message_server_api::poll_message_request* req,
             ::message_server_api::poll_message_response* resp) {
               return service->poll_message(ctx, req, resp);
             }, this)));
}

storage::Service::~Service() {
}

::grpc::Status storage::Service::add_message(::grpc::ServerContext* context, const ::message_server_api::add_message_request* request, ::message_server_api::add_message_response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status storage::Service::poll_message(::grpc::ServerContext* context, const ::message_server_api::poll_message_request* request, ::message_server_api::poll_message_response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace message_server_api
