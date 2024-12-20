protoc = find_program('protoc')
grpc_cpp_plugin = find_program('grpc_cpp_plugin')

proto_generator = generator(protoc, output : ['@BASENAME@.pb.cc', '@BASENAME@.pb.h'],
                            arguments : ['--proto_path=@CURRENT_SOURCE_DIR@',
                                         '--cpp_out=@BUILD_DIR@',
                                         '@INPUT@'])

grpc_generator = generator(protoc, output : ['@BASENAME@.grpc.pb.cc', '@BASENAME@.grpc.pb.h'],
                           arguments : ['--proto_path=@CURRENT_SOURCE_DIR@',
                                        '--grpc_out=@BUILD_DIR@',
                                        '--plugin=protoc-gen-grpc=' + grpc_cpp_plugin.full_path(),
                                        '@INPUT@'])

proto_sources = proto_generator.process('greeter.proto',
                                        preserve_path_from : meson.current_source_dir())

grpc_sources = grpc_generator.process('greeter.proto',
                                      preserve_path_from : meson.current_source_dir())
