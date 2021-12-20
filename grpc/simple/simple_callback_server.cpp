#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server_context.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/support/server_callback.h>
#include <iostream>
#include <grpcpp/grpcpp.h>
#include "../protos/simple/simple.grpc.pb.h"


using grpc::Status;
using grpc::ServerBuilder;
using grpc::CallbackServerContext;
using grpc::ServerUnaryReactor;
using Simple::EchoRequest;
using Simple::EchoResponse;


class SimpleServiceImpl final : public Simple::Server::CallbackService {
    ServerUnaryReactor* Echo(CallbackServerContext* context, const EchoRequest* req, EchoResponse* resp) override {
        resp->set_msg(req->msg());
        ServerUnaryReactor* reactor = context->DefaultReactor();
        reactor->Finish(Status::OK);
        return reactor;
    }
};


int main()
{
    std::string server_address("localhost:12345");
    SimpleServiceImpl service;
    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
    return 0;
}
