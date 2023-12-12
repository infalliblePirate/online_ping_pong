#include "player.h"

game::netPlayer::netPlayer(const sf::Vector2<float> pos, const sf::Vector2<float> size) {
  rect.setPosition(pos);
  rect.setSize(size);
  rect.setFillColor(sf::Color::White);
}

void game::netPlayer::setX(float x) {
  rect.setPosition(x, rect.getPosition().y);
}

float game::netPlayer::getX() const {
  return rect.getPosition().x;
}

sf::RectangleShape game::netPlayer::getRectangle() const {
  return rect;
}

game::player::player(float speed)
        : netPlayer({0, 450}), speed(speed), lastX(rect.getPosition().x), moved(false) {
}

void game::player::update(const std::shared_ptr<input> &input) {
  moved = false;

  if (input->isPressed(sf::Keyboard::D) && rect.getPosition().x < 750 - rect.getSize().x) {
    rect.setPosition(rect.getPosition().x + speed, rect.getPosition().y);
  } else if (input->isPressed(sf::Keyboard::A) && rect.getPosition().x > 0) {
    rect.setPosition(rect.getPosition().x - speed, rect.getPosition().y);
  } else {
    return;
  }
  moved = true;

}

bool game::player::hasMoved() const {
  return moved;
}


