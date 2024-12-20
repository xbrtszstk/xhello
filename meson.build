project('xhello', 'cpp',
        default_options : ['cpp_std=c++23']
)

subdir('protos')
subdir('client')
subdir('server')

install_data('client.toml', install_dir : '/etc')
install_data('server.toml', install_dir : '/etc')
