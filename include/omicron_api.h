#include <string>

class OmicronAPI {
private:
  std::string address_;
  int port_;
  std::string username_;
  std::string password_;

public:
  OmicronAPI(std::string address, int port, std::string username, std::string password);
  std::string ToString();
  bool CheckStatus();
};
