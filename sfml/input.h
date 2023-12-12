#ifndef CLIENT_INPUT_H
#define CLIENT_INPUT_H

#include <SFML/Graphics.hpp>

class input {
public:
    input();

    bool isPressed(sf::Keyboard::Key key);

    static void initWindow(sf::RenderWindow *window);

private:
    static sf::RenderWindow *w;
    sf::Event event{};
};


#endif //CLIENT_INPUT_H
