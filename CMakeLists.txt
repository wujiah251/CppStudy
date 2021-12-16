# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(CppStudy)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置可选项

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# 设置install路径
#set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/runtime/")

# find grpc
# set protobuf
set(protobuf_MODULE_COMPATIBLE True)
find_package(Protobuf REQUIRED)
set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)

# set grpc
find_package( gRPC REQUIRED)
set(_GRPC_GRPCPP_UNSECURE gRPC::grpc++_unsecure)

include_directories(
    ${_PROTOBUF_INCLUDE_DIR}
    /usr/local/include/redis
    ${PROJECT_SOURCE_DIR}/grpc/protos
)
# 添加库文件路径
link_directories(
    /usr/local/lib
)

add_subdirectory(absl)
#add_subdirectory(hiredis)
add_subdirectory(grpc)
add_subdirectory(thread)
add_subdirectory(http)
add_subdirectory(memory)
