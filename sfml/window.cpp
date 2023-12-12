
#include "window.h"


window::window(const std::string title, sf::Vector2<int> size) {
  win.create(sf::VideoMode(size.x, size.y), title);
}

sf::Vector2<unsigned int> window::getSize() {
  return win.getSize();
}

window::~window() {

}

bool window::refresh() {
  win.clear();
  win.pollEvent(event);
  if (event.type == sf::Event::Closed) {
    return false;
  }
}

void window::render(const sf::RectangleShape& pl1, const sf::RectangleShape& pl2, const sf::CircleShape& ball) {
  win.draw(pl1);
  win.draw(pl2);
  win.draw(ball);
  win.display();
}


