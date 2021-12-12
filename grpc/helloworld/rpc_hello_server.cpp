#include <iostream>
#include <grpcpp/security/server_credentials.h>
#include <string>
#include <grpcpp/grpcpp.h>
#include "protos/hello.pb.h"
#include "protos/hello.grpc.pb.h"

class GreeterServiceImpl final : public helloworld::Greeter::Service{
    grpc::Status GetEcho(grpc::ServerContext* context, const helloworld::GetEchoRequest* req, helloworld::GetEchoResponse* resp) override
    {
        std::string msg = req->msg();
        resp->set_msg(msg);
        std::cout << "Recive a rpc request,msg=" << msg << std::endl;
        return grpc::Status::OK;
    }
};


void RunServer() {
    std::string server_address("0.0.0.0:50051");
    GreeterServiceImpl service;
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    fprintf(stdout, "Server listening on: %s\n", server_address.c_str());
    server->Wait();
}

int main()
{
    fprintf(stdout, "server start\n");
    RunServer();
    return 0;
}
