/*
 * Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 */

#include <grpc++/server_builder.h>
#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>

#include "gateway_impl.h"

int main(int argc, char* argv[]) {
    // arg 0: app name
    // arg 1: geo service ip
    // arg2: profile storage service
    // arg3: message storage service
    // arg4: gateway service ip
    if(argc < 5){
        std::cout << "Too few arguments.";
        return - 1;
    }
    auto* geo_service_ip = argv[1];
    auto* profile_storage_ip = argv[2];
    auto* message_storage_ip = argv[2];
    auto* gateway_ip = argv[2];

    core_api::gateway_impl service(
            grpc::CreateChannel(geo_service_ip,
                                grpc::InsecureChannelCredentials()),
            grpc::CreateChannel(profile_storage_ip,
                                grpc::InsecureChannelCredentials()),
            grpc::CreateChannel(message_storage_ip,
                                grpc::InsecureChannelCredentials())

            );
    grpc::ServerBuilder builder;
    builder.AddListeningPort(gateway_ip, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr server(builder.BuildAndStart());
    std::cout << "Server listening on " << gateway_ip << std::endl;
    server->Wait();

    return 0;
}