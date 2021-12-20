#include <iostream>
#include <mutex>
#include <condition_variable>
#include <memory>

#include <grpcpp/grpcpp.h>
#include <grpcpp/security/credentials.h>

#include "../protos/simple/simple.grpc.pb.h"




int main()
{
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:12345",grpc::InsecureChannelCredentials());
    std::unique_ptr<Simple::Server::Stub> stub(Simple::Server::NewStub(channel));
    std::mutex mu;
    std::condition_variable cv;
    grpc::ClientContext ctx;
    Simple::EchoRequest req;
    Simple::EchoResponse resp;
    req.set_msg("hello world");
    grpc::Status status;
    bool done = false;

    stub->async()->Echo(&ctx,&req,&resp,
            [&mu,&cv,&done,&resp,&status](grpc::Status s){
            status = s;
            std::cout << "Callback" << std::endl;
            std::cout << resp.msg() << std::endl;
            std::lock_guard<std::mutex> lock(mu);
            done = true;
            cv.notify_one();
            });
    std::cout << "Start Call" << std::endl;
    std::unique_lock<std::mutex> lock(mu);
    while(!done)
    {
        cv.wait(lock);
    }
    if(status.ok()) {
        std::cout << resp.msg() << std::endl;
    }else{
        std::cout << status.error_code() << ": " << status.error_message() << std::endl;
    }
    return 0;
}
