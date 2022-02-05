/* Copyright (C) 2021 ElectronRock - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/ElectronRock/etherium-chat
 */

#include <grpc++/server_builder.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>

#include "client.h"

int main(int argc, char* argv[]) {
    if(argc == 3) {
        net::client cli(grpc::CreateChannel(argv[1], grpc::InsecureChannelCredentials()),
                        argv[2]);

        cli.run();
    }
    else {
        std::cout << "Incorrect arguments";
    }
    return 0;
}