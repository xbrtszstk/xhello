cmake_minimum_required(VERSION 3.30)
project(rpc)

find_package(spdlog)
find_package(Protobuf)
find_package(gRPC)

find_program(GRPC_CPP_PLUGIN grpc_cpp_plugin)

add_library(${PROJECT_NAME})
add_library(xhello::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        spdlog::spdlog
        gRPC::grpc++
)

target_sources(${PROJECT_NAME}
        PUBLIC
        FILE_SET CXX_MODULES FILES
        client.cppm
        rpc.cppm
        server.cppm
        PRIVATE
        client.cpp
        server.cpp
        xhello.proto
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

protobuf_generate(TARGET ${PROJECT_NAME})
protobuf_generate(TARGET ${PROJECT_NAME}
        LANGUAGE grpc
        PLUGIN protoc-gen-grpc=${GRPC_CPP_PLUGIN}
        GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
)
