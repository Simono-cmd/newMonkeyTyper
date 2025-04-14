#include <SFML/Graphics.hpp>
#include <iostream>

#include "Headers/MainMenu.hpp"

auto main() -> int{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Monkey Typer", sf::Style::Titlebar | sf::Style::Close);

    MainMenu mainMenu(window);
    mainMenu.run();
    return 0;
}