module;

#include <spdlog/spdlog.h>

module configuration;

namespace {
configuration::configuration instance{};
}

void configuration::load() { spdlog::info("configuration::load"); }

const configuration::configuration &configuration::get() {
  spdlog::info("configuration::get");
  return instance;
}
