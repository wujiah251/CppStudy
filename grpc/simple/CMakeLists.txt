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

install(TARGETS
    SimpleServer
    SimpleClient
    SimpleAsyncClient
    SimpleAsyncServer
    DESTINATION bin/
    )
