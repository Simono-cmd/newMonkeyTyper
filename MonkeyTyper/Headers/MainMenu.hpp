#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"


class MainMenu {
public:
    MainMenu(sf::RenderWindow& window);
    void run();

private:
    //main buttons
    sf::RenderWindow& window;
    sf::Font font;
    sf::Font mainfont;
    sf::Text title;
    sf::Text playButton;
    sf::Text easyButton;
    sf::Text mediumButton;
    sf::Text hardButton;
    sf::Text infiniteButton;
    sf::Text exitButton;
    sf::Text loadButton;
    bool isPlayClicked = false;
    bool isPlayHovered;
    bool isEasyHovered;
    bool isMediumHovered;
    bool isHardHovered;
    bool isInfiniteHovered;
    bool isExitHovered;
    bool isLoadHovered;

    void handleEvents();
    void render();
    void startGame(int difficulty);
    sf::Color getRandomColor();




    //changers
    sf::Text config;
    bool isConfigClicked=false;
    bool isConfigHovered;

    sf::Text fontbutton1;
    sf::Text fontbutton2;
    sf::Text fontbutton3;
    sf::Text fontbutton4;
    sf::Text fontbutton5;
    bool fb1h;
    bool fb2h;
    bool fb3h;
    bool fb4h;
    bool fb5h;

    sf::Text sizebutton1;
    sf::Text sizebutton2;
    sf::Text sizebutton3;
    sf::Text sizebutton4;
    sf::Text sizebutton5;
    bool sb1h;
    bool sb2h;
    bool sb3h;
    bool sb4h;
    bool sb5h;


    sf::Font font2;
    sf::Font font3;
    sf::Font font4;
    sf::Font font5;

    void changefont(int fontnum);

    void changesize(int size);

    Game game;

    int readSizeFromSaveGame();
    std::string readFontFromSaveGame();
    int readSpeedFromSaveGame();
    int readGenerateFromSaveGame();
    long readTimerFromSaveGame();
    int readLivesFromSaveGame();
    int readWordsFromSaveGame();
};
