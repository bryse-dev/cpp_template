#include "omicron_api.h"
#include <string>

OmicronAPI::OmicronAPI(std::string address, int port) {
  address_ = address;
  port_ = port;
}

std::string OmicronAPI::ToString() {
  return address_ + ":" + std::to_string(port_);
}
