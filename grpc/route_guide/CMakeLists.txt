add_library(route_guide_helper
    "helper.h"
    "helper.cpp"
    )


add_executable(RouteGuideClient route_guide_client.cpp
    )

target_link_libraries(RouteGuideClient
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    route_guide_proto
    route_guide_helper
    )

add_executable(RouteGuideServer route_guide_server.cpp)

target_link_libraries(RouteGuideServer
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    route_guide_proto
    route_guide_helper
    )

add_executable(TestRouteGuide test_route_guide.cpp)

target_link_libraries(TestRouteGuide
    ${_GRPC_GRPCPP_UNSECURE}
    ${_PROTOBUF_LIBPROTOBUF}
    libbenchmark.a
    route_guide_proto
    route_guide_helper
    )


install(TARGETS
    RouteGuideServer
    RouteGuideClient
    TestRouteGuide
    DESTINATION bin/
    )
