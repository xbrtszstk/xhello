#include <spdlog/spdlog.h>
#include <toml++/toml.h>
#include <grpcpp/grpcpp.h>
#include "greeter.grpc.pb.h"

class GreeterServiceImpl final : public Greeter::Service
{
  grpc::Status SayHello (grpc::ServerContext *context, const HelloRequest *request, HelloReply *reply) override
  {
    reply->set_message ("Hello " + request->name ());
    spdlog::info ("Handling request from {}", request->name ());

    return grpc::Status::OK;
  }
};

int main () {
  std::string server_address{"0.0.0.0:50051"};
  grpc::ServerBuilder builder;
  builder.AddListeningPort (server_address, grpc::InsecureServerCredentials ());
  GreeterServiceImpl service;
  builder.RegisterService (&service);

  std::unique_ptr<grpc::Server> server{builder.BuildAndStart()};
  spdlog::info ("Server listening on {}", server_address);
  server->Wait ();

  return EXIT_SUCCESS;
}
