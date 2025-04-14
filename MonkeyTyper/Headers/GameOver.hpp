#pragma once

#include <SFML/Graphics.hpp>

class GameOver {
public:
    GameOver(sf::RenderWindow& window);
    void display();


private:
    sf::Text gameOverText;
    sf::Text restartText;
    sf::RenderWindow& window;
    sf::Font font;

};

