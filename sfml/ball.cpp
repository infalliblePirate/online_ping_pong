#include <iostream>
#include "ball.h"

game::ball::ball(int id) : x(750. / 2), y(480. / 2), speedX(0.35f), speedY(0.35f) {
  circle.setRadius(10.);
  int speedChoice[]{1,-1};
  speedY *= speedChoice[id];
  circle.setPosition(x, y);
}

game::ball::~ball() {

}

sf::CircleShape game::ball::getCircle() const {
  return circle;
}

void game::ball::update(const sf::RectangleShape &pl1, const sf::RectangleShape &pl2) {
  x += speedX;
  y += speedY;
  circle.setPosition(x, y);

  if (circle.getGlobalBounds().intersects(pl1.getGlobalBounds()) ||
      circle.getGlobalBounds().intersects(pl2.getGlobalBounds())) {
    speedY *= -1;
  }

  if (x < 0 || x + 2 * circle.getRadius() > 750) {
    speedX *= -1;
  } else if (y < 0 || y + 2 * circle.getRadius() > 480) {
    std::cout<<"You lose\n";
    resetPosition();
  }

}

void game::ball::resetPosition() {
  x = 750./2;
  y = 480./2;
  circle.setPosition(x, y);
}


