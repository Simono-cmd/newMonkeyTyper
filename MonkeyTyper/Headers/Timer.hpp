#pragma once

#include <SFML/Graphics.hpp>

class Timer {
public:
    Timer(int seconds);
    void setTimer(long seconds);
    void update();
    void draw(sf::RenderWindow& window);
    void reset();
    int getTime() const;

private:
    int initialSeconds;
    int secondsRemaining;
    sf::Clock clock;
    sf::Font font;
    sf::Text timerText;


};