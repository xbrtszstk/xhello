#include <spdlog/spdlog.h>

import configuration;

int main() {
  spdlog::info("main");

  configuration::load();
  configuration::get();

  return EXIT_SUCCESS;
}
