#include "yaml-cpp/yaml.h"
#include <string>

class Configuration {

public:
  std::string omicron_password;
  std::string omicron_user;
  std::string omicron_address;
  int omicron_port;

  Configuration(std::string config_file_location);
};
