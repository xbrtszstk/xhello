#include <rfl/json.hpp>
#include <spdlog/spdlog.h>

struct Person {
  std::string first_name{};
  std::string last_name{};
  int age{};
};

int main() {
  spdlog::info("Hello from xHello client");

  const auto homer = Person{"Homer", "Simpson", 45};
  rfl::json::write(homer, std::cout) << std::endl;

  return EXIT_SUCCESS;
}
