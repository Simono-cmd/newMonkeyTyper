
#include "../Headers/WinScreen.hpp"

#include <iostream>
#include "../Headers/GameOver.hpp"


WinScreen::WinScreen(sf::RenderWindow& window) : window(window) {
    if (!font.loadFromFile("../Fonts/paul.otf")) {
        std::cerr << "Error loading font file" << std::endl;
        exit(EXIT_FAILURE);
    }

    winText.setFont(font);
    winText.setCharacterSize(150);
    winText.setFillColor(sf::Color(255,40,120));
    winText.setString("You win!!!");
    winText.setOutlineThickness(1);
    winText.setOutlineColor(sf::Color::White);

    sf::FloatRect textBounds = winText.getLocalBounds();
    winText.setPosition((window.getSize().x - textBounds.width) / 2, 150);



}

void WinScreen::display() {
    sf::Texture texture;
    if (!texture.loadFromFile("../Images/flowers.jpg")) {
        std::cerr<<"Error loading a bg!";
    }

    sf::RectangleShape overlay;
    overlay.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    overlay.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    overlay.setTexture(&texture);
    window.draw(overlay);
    window.draw(winText);


    sf::Text restartInfoText;
    restartInfoText.setFont(font);
    restartInfoText.setCharacterSize(60);
    restartInfoText.setFillColor(sf::Color(237, 124, 59));
    restartInfoText.setString("Press F5 to return to main menu");
    restartInfoText.setOutlineThickness(1);
    restartInfoText.setOutlineColor(sf::Color::White);
    sf::FloatRect textWidth = restartInfoText.getLocalBounds();
    restartInfoText.setPosition((window.getSize().x - textWidth.width) / 2, 350);
    window.draw(restartInfoText);

}
