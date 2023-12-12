#ifndef CLIENT_BALL_H
#define CLIENT_BALL_H

#include <SFML/Graphics.hpp>

namespace game {
    class ball {
    public:
        ball(int id);
        ~ball();
        sf::CircleShape getCircle() const;
        void update(const sf::RectangleShape& pl1, const sf::RectangleShape& pl2);
        void resetPosition();
    private:
        int ownerId;
        float x, y;
        float speedX, speedY;
        sf::CircleShape circle;
    };
}


#endif //CLIENT_BALL_H
