module;

#include <string>

export module rpc:server;

export namespace rpc {
class server {
public:
  server(const server &) = delete;
  server(server &&) = delete;
  server &operator=(const server &) = delete;
  server &operator=(server &&) = delete;

  static server &get_instance() noexcept;

  void run(const std::string &addr_uri) const noexcept;

private:
  server() = default;
  ~server() = default;
};
} // namespace rpc
