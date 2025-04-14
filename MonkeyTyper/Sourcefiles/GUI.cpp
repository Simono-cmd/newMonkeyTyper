#include "../Headers/GUI.hpp"
#include <iostream>

GUI::GUI() {
    if (!font.loadFromFile("../Fonts/SugarRush.ttf")) {
        std::cerr << "Error loading font file" << std::endl;
        exit(EXIT_FAILURE);
    }
    wordCounter = 0;
    livesCounter = 0;
    userInput = "";
}

void GUI::setWordCounter(int count) {
    wordCounter = count;
}

sf::Text GUI::getWordCounterText() {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color(157, 217, 117));
    text.setPosition(10, 10);
    text.setString("Correct words: " + std::to_string(wordCounter));
    return text;
}

void GUI::setLivesCounter(int count) {
    livesCounter = count;
}

sf::Text GUI::getLivesCounterText() {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(1070, 750);
    text.setString("Lives: " + std::to_string(livesCounter));
    return text;
}

void GUI::setUserInput(const std::string& input) {
    userInput = input;
}

sf::Text GUI::getUserInputText() {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color(165, 135, 230));
    text.setPosition(10, 750);
    text.setString("Input: " + userInput);
    return text;
}
