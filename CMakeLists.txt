cmake_minimum_required(VERSION 3.30)
project(xhello)

add_subdirectory(client)
add_subdirectory(configuration)
add_subdirectory(rpc)
add_subdirectory(server)

install(FILES configuration.yaml
        DESTINATION ${CMAKE_INSTALL_SYSCONFDIR}/${PROJECT_NAME}
)
