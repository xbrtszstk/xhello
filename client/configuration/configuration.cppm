module;

#include <string>

export module configuration;

export namespace configuration {
struct configuration {
  struct {
    std::string server{"localhost"};
    int port{6379};
  } redis;
};

void load();
const configuration &get();
} // namespace configuration
