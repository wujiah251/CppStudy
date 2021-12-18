#include <grpcpp/security/server_credentials.h>
#include <grpcpp/support/async_unary_call.h>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>


#include "../protos/simple/simple.grpc.pb.h"

using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerCompletionQueue;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerBuilder;
using Simple::EchoRequest;
using Simple::EchoResponse;

class ServerImpl final {
    public:
        ~ServerImpl(){
            _server->Shutdown();
            _cq->Shutdown();
        }
        void Run(){
            std::string server_address("localhost:12345");
            ServerBuilder builder;
            builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
            builder.RegisterService(&_service);
            _cq = builder.AddCompletionQueue();
            _server = builder.BuildAndStart();
            std::cout << "Serfer listening on" << server_address << std::endl;
            // main loop
            HandleRpcs();
        }
    private:
        class CallData {
            public:
                CallData(Simple::Server::AsyncService* service, ServerCompletionQueue* cq)
                    :_service(service), _cq(cq), _responder(&_ctx), _status(CREATE) {
                        Proceed();
                    }
                void Proceed() {
                    if (_status == CREATE) {
                        _status = PROCESS;
                        // 注册请求处理
                        // RequestEcho其实就三确定注册方法Echo
                        // 然后传入处理请求的数据对象
                        // ctx、req、responder_、_cq、this
                        // this对于队列来说是标签
                        _service->RequestEcho(&_ctx, &_req,&_responder,_cq,_cq,this);
                    } else if (_status == PROCESS) {
                        // 已经开始处理一个请求了，生成一个新对象供下一个使用
                        new CallData(_service, _cq); // 会调用proceed注册请求
                        _resp.set_msg(_req.msg());
                        _status = FINISH;
                        _responder.Finish(_resp, Status::OK, this);
                    } else {
                        GPR_ASSERT(_status == FINISH);
                        delete this;
                    }
                }
            private:
                Simple::Server::AsyncService* _service;
                ServerCompletionQueue* _cq;
                ServerContext _ctx;
                EchoRequest _req;
                EchoResponse _resp;
                ServerAsyncResponseWriter<EchoResponse> _responder;
                enum CallStatus { CREATE, PROCESS, FINISH};
                CallStatus _status;
        };

        void HandleRpcs() {
            new CallData(&_service, _cq.get());
            void* tag;
            bool ok;
            while(true){
                GPR_ASSERT(_cq->Next(&tag, &ok));
                GPR_ASSERT(ok);
                static_cast<CallData*>(tag)->Proceed();
            }
        }
        std::unique_ptr<ServerCompletionQueue> _cq;
        Simple::Server::AsyncService _service;
        std::unique_ptr<grpc::Server> _server;
};



int main()
{
    ServerImpl server;
    server.Run();
    return 0;
}
