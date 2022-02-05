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
        self.stub = message_server_pb2_grpc.storageStub(self.channel)
        message_server_pb2.
 
    def poll(self):
        pass
        
    def register(self, name):
        pass
        
    def send(self):
        pass