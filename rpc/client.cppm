module;

#include <string>

export module rpc:client;

export namespace rpc {
class client {
public:
  client(const client &) = delete;
  client(client &&) = delete;
  client &operator=(const client &) = delete;
  client &operator=(client &&) = delete;

  static client &get_instance() noexcept;

  void run(const std::string &target) const noexcept;

private:
  client() = default;
  ~client() = default;
};
} // namespace rpc
