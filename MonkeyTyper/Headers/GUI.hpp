#pragma once

#include <SFML/Graphics.hpp>

class GUI {
public:
    GUI();

    void setWordCounter(int count);
    sf::Text getWordCounterText();

    void setLivesCounter(int count);
    sf::Text getLivesCounterText();

    void setUserInput(const std::string& input);
    sf::Text getUserInputText();

private:
    sf::Font font;
    int wordCounter;
    int livesCounter;
    std::string userInput;

};