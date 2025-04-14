#pragma once
#include<set>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Word {
public:
    Word(const std::string& str, const sf::Font& font, float y, float speed, int size);

    void update(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;

    std::string getText() const;

    void setColor(Word word, sf::Color color, int thickness);



private:
    sf::Text text;
    float speed;

    sf::Clock clock;
    std::string originalText;


};


