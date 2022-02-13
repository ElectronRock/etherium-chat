import logging

import grpc
import message_server_pb2
import message_server_pb2_grpc

class cli:
    def __init__(self):
        self.name = ""
        self.last_message_id = 0

    def initialize(self, name, host):
        self.channel = grpc.insecure_channel(host)
        self.client_impl = message_server_pb2_grpc.storageStub(self.channel)
        return self.register(name)
 
    def poll(self):
        request = message_server_pb2.poll_message_request(last_polled_message_id=self.last_message_id,
                                                          client_id=self.name)
        response = self.client_impl.poll_message(request)
        messages = []
        for i in range(0, len(response.text)):
            messages.append((response.client_id[i], response.text[i]))
            self.last_message_id = response.message_id[i]
        return messages
        
    def register(self, name):
        request = message_server_pb2.register_client_request(prefered_client_id=name)
        response = self.client_impl.register_client(request)
        self.name = response.client_id
        return self.name

    def send(self, text_to_send):
        request = message_server_pb2.add_message_request(client_id=self.name, text=text_to_send)
        self.client_impl.add_message(request)
