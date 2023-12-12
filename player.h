#ifndef CLIENT_PLAYER_H
#define CLIENT_PLAYER_H

#include "sfml/input.h"
#include <SFML/Graphics.hpp>
#include <memory>


namespace game {

    class netPlayer {
    public:
        netPlayer(const sf::Vector2<float> pos, const sf::Vector2<float> size = {125, 25});

        void setX(float x);

        float getX() const;
        sf::RectangleShape getRectangle() const;

    protected:
        sf::RectangleShape rect;
    };

    class player : public netPlayer {
    public:
        player(float speed = 10.0f);
       void update(const std::shared_ptr<input>& input);
       bool hasMoved() const;

    private:
        const float speed;
        float lastX;
        bool moved;
    };
}

#endif //CLIENT_PLAYER_H
