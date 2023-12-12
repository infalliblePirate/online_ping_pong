#include "input.h"

sf::RenderWindow *input::w;

input::input() {

}

bool input::isPressed(sf::Keyboard::Key key) {
  if (w->hasFocus()) {
    return sf::Keyboard::isKeyPressed(key);
  }
  return false;
}

void input::initWindow(sf::RenderWindow *window) {
  w = window;
}


