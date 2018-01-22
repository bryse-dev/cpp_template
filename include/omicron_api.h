#include <string>

class OmicronAPI {
private:
  std::string address_;
  int port_;

public:
  OmicronAPI(std::string address, int port);
  std::string ToString();
};
