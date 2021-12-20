#include <grpcpp/support/async_unary_call.h>
#include <iostream>
#include <memory>
#include <chrono>
#include <unistd.h>

#include <grpcpp/grpcpp.h>
#include <sstream>

#include "../../thread/thread_pool/thread_pool.h"
#include "../protos/simple/simple.grpc.pb.h"


// 维护基础的上下文信息
struct HandlerContextBase
{
    int _type;   // 对象类型，用于确定是哪个请求

    enum Status {
        PROCEESS = 1,   // 构建响应完成
        FINISH = 2      // 发送响应
    };
    Status _status;
    grpc::ServerContext _ctx;    // 上下文
};

template<typename RequestType, typename ResponseType>
struct HandlerContext:public HandlerContextBase{
    RequestType _req;
    ResponseType _resp;
    grpc::ServerAsyncResponseWriter<ResponseType> _responder;
    HandlerContext(): _responder(&_ctx){}
};

typedef HandlerContext<Simple::EchoRequest,Simple::EchoResponse> HandlerEchoContext;

unsigned long get_tid()
{
    std::thread::id tid = std::this_thread::get_id();
    std::ostringstream os;
    os << tid;
    unsigned long tidx = std::stol(os.str());
    return tidx;
}

grpc::Status Echo(grpc::ServerContext* context,
        const Simple::EchoRequest* req,
        Simple::EchoResponse* resp)
{
    int tid = get_tid();
    std::cout << "Get Echo Request = " << req->msg() << std::endl;
    sleep(1);
    std::ostringstream os;
    os << "Echo msg = " << req->msg() << '\n';
    os << "Server TID = " <<  tid << '\n';
    std::string message = os.str();
    resp->set_msg(req->msg());
    return grpc::Status(grpc::StatusCode::OK, message);
}


int main()
{
    grpc::ServerBuilder builder;
    builder.AddListeningPort("localhost:12345", grpc::InsecureServerCredentials());
    // 创建一个异步服务对象
    Simple::Server::AsyncService service;
    builder.RegisterService(&service);
    // 添加一个完成队列，用于与gRPC运行时异步通信
    std::unique_ptr<grpc::ServerCompletionQueue> cq_ptr = builder.AddCompletionQueue();
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server Runing" << std::endl;

    for(int i=0;i<4;++i)
    {
        HandlerEchoContext *htx_echo = new HandlerEchoContext;
        htx_echo->_type = 1;
        htx_echo->_status = HandlerContextBase::PROCEESS;

        service.RequestEcho(&htx_echo->_ctx,&htx_echo->_req,&htx_echo->_responder,cq_ptr.get(),cq_ptr.get(),htx_echo);
    }
    ThreadPool pool(4);
    // 异步服务这里不能使用server->Wait()来等待处理，因为是异步服务
    while(true)
    {
        HandlerContextBase* htc = NULL;
        bool ok = false;
        GPR_ASSERT(cq_ptr->Next((void**)&htc, &ok));
        GPR_ASSERT(ok);
        int type = htc->_type;
        if(htc->_status == HandlerContextBase::FINISH){
            switch(htc->_type){
                case 1:
                    {
                        delete (HandlerEchoContext*)htc;
                    }
                    break;
            }
            continue;
        }else if(htc->_status == HandlerContextBase::PROCEESS)
        {
            switch(htc->_type){
                case 1:
                    {
                        HandlerEchoContext* htc1 = new HandlerEchoContext;
                        htc1->_status = HandlerContextBase::PROCEESS;
                        htc1->_type = 1;
                        service.RequestEcho(&htc1->_ctx,&htc1->_req,&htc1->_responder,
                                cq_ptr.get(),cq_ptr.get(),htc1);

                    }
                    break;
            }
        }
        pool.enqueue([type,htc](){
                switch(type){
                case 1:
                {
                HandlerEchoContext* h = (HandlerEchoContext*)htc;
                grpc::Status status = Echo(&h->_ctx,&h->_req,&h->_resp);
                h->_status = HandlerContextBase::FINISH;
                h->_responder.Finish(h->_resp,grpc::Status::OK,htc);
                }
                break;
                }
                });


    }
    return 0;
}
