#include <iostream>
#include "network.h"
#include <memory>

int main() {
  auto server = std::make_unique<network::server>();

  std::cout << "listening (default: 127.0.0.1:8192)\n";
  while(true) {
    server->handle();
  }
}
