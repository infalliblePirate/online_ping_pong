
#ifndef CLIENT_WINDOW_H
#define CLIENT_WINDOW_H

#include <SFML/Graphics.hpp>


class window {
public:
    window( const std::string title, sf::Vector2<int> size = {750, 480});
    ~window();

    bool refresh();
    sf::Vector2<unsigned int> getSize();

    void render(const sf::RectangleShape& pl1, const sf::RectangleShape& pl2, const sf::CircleShape& ball);
    sf::RenderWindow win;
private:
    sf::Event event{};

};


#endif //CLIENT_WINDOW_H
