add_executable(SimpleClient simple_client.cpp)

target_link_libraries(SimpleClient
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    simple_proto
    )

add_executable(SimpleServer simple_server.cpp)

target_link_libraries(SimpleServer
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    simple_proto
    )

add_executable(SimpleAsyncClient simple_async_client.cpp)

target_link_libraries(SimpleAsyncClient
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    simple_proto
    )

add_executable(SimpleAsyncServer simple_async_server.cpp)

target_link_libraries(SimpleAsyncServer
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    simple_proto
    )

add_executable(SimpleAsyncServer2 simple_async_server2.cpp)

target_link_libraries(SimpleAsyncServer2
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    simple_proto
    )

add_executable(SimpleClient2 simple_client2.cpp)

target_link_libraries(SimpleClient2
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    simple_proto
    )

add_executable(SimpleCallbackClient simple_callback_client.cpp)

target_link_libraries(SimpleCallbackClient
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    simple_proto
    )

add_executable(SimpleCallbackServer simple_callback_server.cpp)

target_link_libraries(SimpleCallbackServer
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    libgrpc++_reflection.a
    simple_proto
    )

install(TARGETS
    SimpleServer
    SimpleClient
    SimpleAsyncClient
    SimpleAsyncServer
    SimpleAsyncServer2
    SimpleClient2
    SimpleCallbackClient
    SimpleCallbackServer
    DESTINATION bin/
    )
