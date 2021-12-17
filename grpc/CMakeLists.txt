

add_library(route_guide_proto
    "protos/route_guide/route_guide.grpc.pb.cc"
    "protos/route_guide/route_guide.pb.cc"
    )
add_library(simple_proto
    "protos/simple/simple.grpc.pb.cc"
    "protos/simple/simple.pb.cc"
    )


add_subdirectory(helloworld)
add_subdirectory(route_guide)
add_subdirectory(simple)
