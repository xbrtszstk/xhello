module;

#include "xhello.grpc.pb.h"
#include <expected>
#include <grpc++/grpc++.h>
#include <spdlog/spdlog.h>

module rpc;

namespace {
class service {
public:
  explicit service(const std::shared_ptr<grpc::Channel> &channel) noexcept {
    m_stub = xhello::service::NewStub(channel);
  }

  [[nodiscard]] std::expected<std::string, std::string> rpc(const std::string &name) const noexcept {
    xhello::request request;
    xhello::response response;
    grpc::ClientContext context;

    request.set_name(name);

    if (const auto result = m_stub->rpc(&context, request, &response); result.ok()) {
      return response.message();
    } else {
      return std::unexpected{result.error_message()};
    }
  }

private:
  std::unique_ptr<xhello::service::Stub> m_stub;
};
} // namespace

rpc::client &rpc::client::get_instance() noexcept {
  static client instance;
  return instance;
}

void rpc::client::run(const std::string &target) const noexcept {
  const auto creds{grpc::InsecureChannelCredentials()};
  const auto channel{grpc::CreateChannel(target, creds)};
  const service service{channel};

  const auto name = "xbrtszstk";
  if (const auto result = service.rpc(name); result) {
    spdlog::info("{}", result.value());
  } else {
    spdlog::error("{}", result.error());
  }
}
