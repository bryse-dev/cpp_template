#include "omicron_api.h"
#include <iostream>
using namespace std;

// main() is where program execution begins.
int main() {
  OmicronAPI api("127.0.0.1", 5000);
  cout << api.ToString() << std::endl;
  return 0;
}
