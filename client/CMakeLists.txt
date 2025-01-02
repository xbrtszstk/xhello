cmake_minimum_required(VERSION 3.30)
project(xhello-client)

find_package(spdlog)
add_subdirectory(configuration)

add_executable(${PROJECT_NAME} main.cpp)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        spdlog::spdlog
        module::configuration
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES configuration.yaml
        DESTINATION ${CMAKE_INSTALL_SYSCONFDIR}/xhello
        RENAME client.yaml
)
