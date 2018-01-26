#include "configuration.h"
#include "log4cpp/Category.hh"
#include "yaml-cpp/yaml.h"
#include <fstream>
#include <string>

Configuration::Configuration(std::string config_file_location) {

  // Get logger
  log4cpp::Category &root = log4cpp::Category::getRoot();

  // Parse yaml
  YAML::Node node = YAML::LoadFile(config_file_location);

  // TODO: Make it so that you can pass multiple Omicron hosts
  // Assign to class variables
  omicron_address = node["omicron_address"].as<std::string>();
  omicron_port = node["omicron_port"].as<int>();
  omicron_user = node["omicron_user"].as<std::string>();
  omicron_password_ = node["omicron_password"].as<std::string>();
}
