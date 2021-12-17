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

install(TARGETS
    SimpleServer
    SimpleClient
    DESTINATION bin/
    )
