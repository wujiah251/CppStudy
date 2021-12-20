#include <iostream>
#include <string>
#include <vector>
#include <thread>

#include <grpcpp/grpcpp.h>
#include <grpcpp/channel.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/security/credentials.h>

#include "../protos/simple/simple.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;

int main()
{
    // 创建一个channel，维护的是和服务器的连接
    std::vector<std::thread> multi_echo;

    for(int i=0;i<10;++i)
    {
        multi_echo.emplace_back(std::thread([i]{
                    std::shared_ptr<Channel> chan = grpc::CreateChannel("localhost:12345",grpc::InsecureChannelCredentials());
                    // 创建一个stub
                    std::unique_ptr<Simple::Server::Stub> stub = Simple::Server::NewStub(chan);
                    Simple::EchoRequest req;
                    Simple::EchoResponse resp;
                    ClientContext ctx;
                    std::string message = "no." + std::to_string(i);
                    req.set_msg(message);
                    auto status = stub->Echo(&ctx,req,&resp);
                    std::cout << status.error_message();
                    std::cout << resp.msg() << std::endl;
                    }));
    }
    for(auto& worker:multi_echo)
    {
        worker.join();
    }
    return 0;
}
