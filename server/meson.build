executable('xhello-server', 'main.cpp', proto_sources, grpc_sources,
           dependencies : [
               dependency('spdlog'),
               dependency('reflectcpp'),
               dependency('protobuf'),
               dependency('grpc++'),
               dependency('redis++')
           ],
           install : true
)

install_data('config.toml', install_dir : '/etc/server.toml')
