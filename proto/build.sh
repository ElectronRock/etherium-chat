./protoc --grpc_out=. --plugin=protoc-gen-grpc=grpc_cpp_plugin message_storage.proto
./protoc --cpp_out=. message_storage.proto
