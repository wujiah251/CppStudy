#include <iostream>

#include <grpc++/grpc++.h>
#include <grpc++/security/credentials.h>

#include "../protos/simple/simple.grpc.pb.h"
// 添加自己的路径

using grpc::Status;
using grpc::ServerContext;


class SimpleServiceImpl final : public Simple::Server::Service{
    public:
        Status Echo(ServerContext* context,
                const Simple::EchoRequest* req,
                Simple::EchoResponse* resp)override
        {
            resp->set_msg(req->msg());
            return Status::OK;
        }
};

int main()
{
    // 服务器构建器
    grpc::ServerBuilder builder;
    // 添加监听的地址和端口，选择不认证
    builder.AddListeningPort("localhost:12345",grpc::InsecureServerCredentials());
    // 注册服务
    SimpleServiceImpl service;
    builder.RegisterService(&service);
    // 构建服务器
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server running" << std::endl;
    // 进入服务器处理循环
    server->Wait();
    return 0;
}
