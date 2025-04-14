#include <iostream>
#include "../Headers/GameOver.hpp"

GameOver::GameOver(sf::RenderWindow& window) : window(window) {
    if (!font.loadFromFile("../Fonts/john.ttf")) {
        std::cerr << "Error loading font file" << std::endl;
        exit(EXIT_FAILURE);
    }

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(120);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("Game Over");
    gameOverText.setOutlineThickness(1);
    gameOverText.setOutlineColor(sf::Color::Black);

    sf::FloatRect textBounds = gameOverText.getLocalBounds();
    gameOverText.setPosition((window.getSize().x - textBounds.width) / 2, 200);

}

void GameOver::display() {
    sf::Texture texture;
    if (!texture.loadFromFile("../Images/flames.jpg")) {
        std::cerr<<"Error loading a bg!";
    }

    sf::RectangleShape overlay;
    overlay.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    overlay.setTexture(&texture);
    window.draw(overlay);
    window.draw(gameOverText);


    sf::Text restartInfoText;
    restartInfoText.setFont(font);
    restartInfoText.setCharacterSize(30);
    restartInfoText.setFillColor(sf::Color::White);
    restartInfoText.setString("Press F5 to return to main menu");
    restartInfoText.setOutlineThickness(1);
    restartInfoText.setOutlineColor(sf::Color::Black);
    sf::FloatRect textWidth = restartInfoText.getLocalBounds();
    restartInfoText.setPosition((window.getSize().x - textWidth.width) / 2, 400);
    window.draw(restartInfoText);
}

