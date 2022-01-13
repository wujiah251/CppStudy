# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.16)

# 项目名称
project(CppStudy)

set(CMAKE_CXX_STANDARD 17)
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

# find boost
find_package(Boost COMPONENTS log log_setup REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
endif()

# find mongocxx
find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")

include_directories(
    ${_PROTOBUF_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/grpc/protos
    /usr/local/include
    /usr/local/include/mongocxx/v_noabi
    /usr/local/include/bsoncxx/v_noabi
    /usr/local/include/libmongoc-1.0
    /usr/local/include/libbson-1.0
    )
# 添加库文件路径
link_directories(
    /usr/local/lib
    /usr/lib
    /usr/local/lib/mongocxx/v_noabi
    /usr/local/lib/bsoncxx/v_noabi
    )

#add_subdirectory(absl)
#add_subdirectory(hiredis)
#add_subdirectory(grpc)
#add_subdirectory(thread)
#add_subdirectory(http)
#add_subdirectory(memory)
add_subdirectory(log)
add_subdirectory(boost)
add_subdirectory(simhash)
add_subdirectory(mongodb)
