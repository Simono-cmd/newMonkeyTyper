#pragma once

#include <SFML/Graphics.hpp>

class WinScreen {
public:
    WinScreen(sf::RenderWindow& window);
    void display();

private:
    sf::Text winText;
    sf::Text restartText;
    sf::RenderWindow& window;
    sf::Font font;

};
