module;

#include "xhello.grpc.pb.h"
#include <grpc++/grpc++.h>
#include <spdlog/spdlog.h>

module rpc;

namespace {
class service final : public xhello::service::Service {
public:
  grpc::Status rpc(grpc::ServerContext *context,
                   const xhello::request *request,
                   xhello::response *response) override {
    const auto prefix("Hello, ");
    response->set_message(prefix + request->name());

    return grpc::Status::OK;
  }
};
} // namespace

rpc::server &rpc::server::get_instance() noexcept {
  static server instance;
  return instance;
}

void rpc::server::run(const std::string &addr_uri) const noexcept {
  grpc::ServerBuilder builder;

  const auto creds{grpc::InsecureServerCredentials()};
  builder.AddListeningPort(addr_uri, creds);

  service service;
  builder.RegisterService(&service);

  const auto server(builder.BuildAndStart());
  server->Wait();
}
