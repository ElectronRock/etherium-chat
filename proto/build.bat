protoc --grpc_out=. --plugin=protoc-gen-grpc=grpc_cpp_plugin.exe message_server.proto
protoc --cpp_out=. message_server.proto
