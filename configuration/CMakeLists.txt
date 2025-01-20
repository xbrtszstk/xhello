cmake_minimum_required(VERSION 3.30)
project(configuration)

find_package(spdlog)
find_package(reflectcpp)

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
        reflectcpp::reflectcpp
)

target_sources(${PROJECT_NAME}
        PUBLIC
        FILE_SET CXX_MODULES FILES
        configuration.cppm
        PRIVATE
        configuration.cpp
)
