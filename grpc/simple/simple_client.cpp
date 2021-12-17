#include <iostream>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/channel.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/security/credentials.h>

#include "../protos/simple/simple.grpc.pb.h"

using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;

int main()
{
    // 创建一个channel，维护的是和服务器的连接
    std::shared_ptr<Channel> chan = grpc::CreateChannel("localhost:12345",grpc::InsecureChannelCredentials());
    // 创建一个stub
    std::unique_ptr<Simple::Server::Stub> stub = Simple::Server::NewStub(chan);

    Simple::EchoRequest req;
    req.set_msg("Hello World");
    Simple::EchoResponse resp;
    ClientContext context;
    Status st = stub->Echo(&context,req,&resp);
    if(st.ok()){
        std::cout << resp.msg() <<std::endl;
    }
    return 0;
}
