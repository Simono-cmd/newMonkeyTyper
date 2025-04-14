#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Word.hpp"
#include "GUI.hpp"
#include "Timer.hpp"
#include "GameOver.hpp"
#include "WinScreen.hpp"

class Game {
public:

    Game(sf::RenderWindow& gameWindow);
    void run();
    void setDifficulty(long time, int lives, int speed, int generate, int correctwords);
    int difficulty_generate=8;
    int difficulty_speed=50;
    int correctwords=0;
    int charsize = 20;
    std::string fonttype ="..//Fonts/arial.ttf";
    int lives;


    void setCharsize(int charsize);

    void setFonttype(const std::string &fonttype);

private:

    bool gameOver = false;
    bool isPaused = false;
    bool isPausedDrawn = false;

    sf::RenderWindow& window;
    sf::Font font;
    std::vector<std::string> wordsList;
    std::vector<Word> words;
    std::string inputPhrase;
    sf::Clock clock;

    void loadWordsFromFile(const std::string& filename);
    void displayWords();
    void handleInput(char inputChar);
    int correctWordCount();
    void counters();
    void resetGame();
    void returnToMainMenu();
    void drawPauseScreen();
    void displaySavedGame();
    void saveGameToFile();


    GUI gui;
    Timer timer;
    GameOver gameoverscreen;
    WinScreen winscreen;

};
