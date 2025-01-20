#include <cxxopts.hpp>
#include <iostream>
#include <spdlog/spdlog.h>

import configuration;
import rpc;

int main(const int argc, const char *const *argv) {
  try {
    cxxopts::Options options("xhello-server", "1.0");

    options.add_options()
      ("h,help", "- displays help message")
      ("c,config", "- path to configuration file", cxxopts::value<std::string>());

    const auto result = options.parse(argc, argv);

    if (result.count("help")) {
      std::cout << options.help() << std::endl;
      return EXIT_SUCCESS;
    }

    if (result.count("config")) {
      const auto path{result["config"].as<std::string>()};
      configuration::get_instance().load(path);
    }
  } catch (const cxxopts::exceptions::exception &exception) {
    spdlog::error("{}", exception.what());
    return EXIT_FAILURE;
  }

  const auto addr_uri{std::format("{}:{}",
    configuration::get_instance().get_data().server.address,
    configuration::get_instance().get_data().server.port)};
  rpc::server::get_instance().run(addr_uri);

  return EXIT_SUCCESS;
}
