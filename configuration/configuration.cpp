module;

#include <rfl/yaml.hpp>
#include <spdlog/spdlog.h>

module configuration;

configuration::configuration() noexcept {
  m_data = std::make_unique<data>();
}

configuration &configuration::get_instance() noexcept {
  static configuration instance;
  return instance;
}

const configuration::data &configuration::get_data() const noexcept {
  return *m_data;
}

void configuration::load(const std::string &path) const noexcept {
  if (const auto result = rfl::yaml::load<data>(path); !result) {
    spdlog::error("{}", result.error().value().what());
  } else {
    *m_data = result.value();
  }
}
