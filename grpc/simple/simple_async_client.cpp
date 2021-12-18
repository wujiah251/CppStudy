#include <grpcpp/completion_queue.h>
#include <grpcpp/security/credentials.h>
#include <grpcpp/support/async_unary_call.h>
#include <iostream>

#include <grpcpp/grpcpp.h>

#include "../protos/simple/simple.grpc.pb.h"

using grpc::Status;
using grpc::Channel;
using grpc::CompletionQueue;
using grpc::ClientContext;
using grpc::ClientAsyncResponseReader;
using Simple::EchoRequest;
using Simple::EchoResponse;

int main()
{
    std::shared_ptr<Channel> chan = grpc::CreateChannel("localhost:12345",grpc::InsecureChannelCredentials());
    std::unique_ptr<Simple::Server::Stub> stub(Simple::Server::NewStub(chan));

    ClientContext context;
    EchoRequest req;
    req.set_msg("hello world!");
    EchoResponse resp;
    CompletionQueue cq;
    std::unique_ptr<ClientAsyncResponseReader<EchoResponse>> rpc(stub->AsyncEcho(&context, req, &cq));
    Status status;
    // 第三个参数是一个上下文标签，用于帮我们标识这个请求
    // grpc框架只会将其保存起来
    rpc->Finish(&resp, &status, (void*)1);
    void* got_tag;
    bool ok = false;
    // 从队列中获取，请求的标签以及状态
    cq.Next(&got_tag, &ok);
    if(ok && got_tag == (void*)1){
        // check一下结果
        std::cout << resp.msg() << std::endl;
    }
    return 0;
}
