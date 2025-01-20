module;

#include <memory>

export module configuration;

export class configuration {
public:
  struct data {
    struct {
      std::string address{"0.0.0.0"};
      int port{50051};
    } server;
    struct {
      std::string address{"192.168.8.160"};
      int port{50051};
    } client;
  };

  configuration(const configuration &) = delete;
  configuration(configuration &&) = delete;
  configuration &operator=(const configuration &) = delete;
  configuration &operator=(configuration &&) = delete;

  static configuration &get_instance() noexcept;

  [[nodiscard]] const data &get_data() const noexcept;
  void load(const std::string &path) const noexcept;

private:
  configuration() noexcept;
  ~configuration() = default;

  std::unique_ptr<data> m_data;
};
