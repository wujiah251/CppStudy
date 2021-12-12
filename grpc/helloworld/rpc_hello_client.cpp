#include <grpcpp/grpcpp.h>
#include <string>
#include <iostream>
#include <memory>
#include "protos/hello.grpc.pb.h"
#include "protos/hello.pb.h"
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::GetEchoRequest;
using helloworld::GetEchoResponse;
using helloworld::Greeter;

class GreeterClient
{
    private:
        std::unique_ptr<Greeter::Stub> stub_;
    public:
        GreeterClient(std::shared_ptr<Channel> channel)
            : stub_(Greeter::NewStub(channel)) {}
        std::string SayHello(const std::string& msg)
        {
            GetEchoRequest request;
            request.set_msg(msg);
            GetEchoResponse response;
            ClientContext context;
            Status status = stub_->GetEcho(&context, request, &response);
            if(status.ok())
            {
                return response.msg();
            }else{
                std::cout << status.error_code() << ": " << status.error_code() << std::endl;
                return "RPC Failed";
            }
        }
};

int main(int argc, char* argv[])
{
    std::string target_str;
    std::string arg_str("--target");
    if (argc > 1)
    {
        std::string arg_val = argv[1];
        size_t start_pos = arg_val.find(arg_str);
        if (start_pos != std::string::npos)
        {
            start_pos += arg_str.size();
            if (arg_val[start_pos] == '=') 
            {
                target_str = arg_val.substr(start_pos + 1);
            } else {
                std::cout << "The only correct arument syntax is --target=" << std::endl;
                return 0;
            }
        } else {
            std::cout << "The only acceptable argument is --target=" << std::endl;
            return 0;
        }
    }
    else {
        target_str = "localhost:50051";
    }
    GreeterClient greeter(grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
    std::string msg("hello world");
    std::string reply = greeter.SayHello(msg);
    std::cout << "Greeter received: " << reply << std::endl;
    return 0;
}
