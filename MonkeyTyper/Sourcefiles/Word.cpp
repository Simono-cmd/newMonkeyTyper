#include "../Headers/Word.hpp"

Word::Word(const std::string& str, const sf::Font& font, float y, float speed, int size)
        : speed(speed){
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);
    text.setPosition(0, y);
}

void Word::update(sf::RenderWindow& window) {
    sf::Time deltaTime = clock.restart();
    text.move(speed * deltaTime.asSeconds(), 0);
}

void Word::draw(sf::RenderWindow& window) {
    window.draw(text);
}

sf::Vector2f Word::getPosition() const {
    return text.getPosition();
}

std::string Word::getText() const {
    return text.getString();
}

void Word::setColor(Word word, sf::Color color, int thickness){
        text.setFillColor(color);
        text.setOutlineColor(color);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(thickness);

}















