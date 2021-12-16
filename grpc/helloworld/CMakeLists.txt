add_executable(RpcHelloServer
    rpc_hello_server.cpp
    protos/hello.pb.cc
    protos/hello.grpc.pb.cc
    )
target_link_libraries(RpcHelloServer
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    )

add_executable(RpcHelloClient
    rpc_hello_client.cpp
    protos/hello.pb.cc
    protos/hello.grpc.pb.cc
    )

target_link_libraries(RpcHelloClient
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    )

install(TARGETS
    RpcHelloServer
    RpcHelloClient
    DESTINATION bin/
    )
