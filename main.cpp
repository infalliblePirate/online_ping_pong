#include <iostream>
#include <memory>
#include "network.h"
#include "player.h"
#include "sfml/window.h"
#include "sfml/input.h"
#include "sfml/ball.h"
#include <thread>
#include <chrono>

int main() {

  std::string ip;
  std::cout << "ip (default 127.0.0.1): ";
  getline(std::cin, ip);
  if (ip.empty()) {
    ip = "127.0.0.1";
  }

  std::string port;
  std::cout << "port (default 8192) ";
  if (port.empty()) {
    port = "8192";
  }

  std::cout << "trying to connect... (" << ip << ":" << port << ")\n";

  if (auto client = std::make_unique<network::client>(ip, stoi(port)); client->connect()) {
    auto w = std::make_unique<window>("ping-pong");
    auto in = std::make_shared<input>();
    input::initWindow(&w->win);

    auto player = std::make_unique<game::player>(1);
    auto opponent = std::make_unique<game::netPlayer>(sf::Vector2<float>(0, 0));

    std::unique_ptr<game::ball> ball;
    bool canStart = false;
    bool isSetId = false;

    while (w->refresh()) {
      client->handle([&](uint16_t id, const network::packet &packet) {
          if (packet.type == network::packetType::updatePosition) {
            if (packet.id != id) {
              opponent->setX(packet.x);
              std::cout << "set position" << std::endl;
            }
          }
          if (packet.id == 1 || id == 1)
            canStart = true;
      }, &isSetId);

      if (isSetId) { // ball's speedY coordinate is positive if id is 0, negative if 1
        ball = std::make_unique<game::ball>(client->getId());
        isSetId = false;
      }

      if (player->hasMoved()) {
        client->send({network::packetType::updatePosition, client->getId(), player->getX()});
      }
      player->update(in);

      if (canStart) {
        ball->update(player->getRectangle(), opponent->getRectangle());
        w->render(player->getRectangle(), opponent->getRectangle(), ball->getCircle());
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
  }
  return 0;
}
