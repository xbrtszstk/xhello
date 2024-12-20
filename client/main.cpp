#include <spdlog/spdlog.h>
#include <toml++/toml.h>
#include <grpcpp/grpcpp.h>
#include "greeter.grpc.pb.h"

int main ()
{
  std::string server_address{"0.0.0.0:50051"};
  auto channel = grpc::CreateChannel (server_address, grpc::InsecureChannelCredentials ());
  std::unique_ptr<Greeter::Stub> stub{Greeter::NewStub (channel)};

  grpc::ClientContext context{};
  HelloRequest request{};
  HelloReply reply{};

  request.set_name ("World");

  if (auto status = stub->SayHello (&context, request, &reply); status.ok ())
    spdlog::info ("Response: {}", reply.message ());
  else
    spdlog::error ("RPC failed: {}", status.error_message ());

  return EXIT_SUCCESS;
}
