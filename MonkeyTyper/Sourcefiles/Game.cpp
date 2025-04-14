#include "../Headers/Game.hpp"
#include "../Headers/MainMenu.hpp"
#include <set>

Game::Game(sf::RenderWindow& gameWindow) : window(gameWindow),
                                           gameOver(false),
                                           gameoverscreen(window),
                                           winscreen(window),
                                           timer(60)
                                           {

    loadWordsFromFile("../Files/words.txt");
    srand(static_cast<unsigned int>(time(nullptr)));

    font.loadFromFile(fonttype);
}

void Game::run() {
    sf::Texture texture;
    if (!texture.loadFromFile("../Images/bg1.jpg")) {
        std::cerr<<"Error loading a bg!";
    }

    sf::RectangleShape overlay;
    overlay.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    overlay.setTexture(&texture);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered) {
                char inputChar = static_cast<char>(event.text.unicode);
                handleInput(inputChar);
            }
            if (gameOver || isPaused) {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
                    returnToMainMenu();
                }
            }
            if (isPaused) {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F6) {
                  displaySavedGame();
                  saveGameToFile();
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    isPaused = !isPaused;
                }
            }

        }

        if (!isPaused) {
            window.clear();
            window.draw(overlay);
            if (!gameOver) {
                displayWords();
                counters();
                timer.update();
                timer.draw(window);
                if (timer.getTime() <= 0 && lives > 0) {
                    gameOver = true;
                }
            } else {
                if (lives > 0) {
                    winscreen.display();
                } else {
                    gameoverscreen.display();
                }
            }
            window.display();
        }
        if(isPaused)
        {
            if(!isPausedDrawn){drawPauseScreen();}
        }
    }
}

void Game::loadWordsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string word;
    std::set<std::string> uniqueWords;
    while (file >> word) {
        uniqueWords.insert(word);
    }
    file.close();

    wordsList.assign(uniqueWords.begin(), uniqueWords.end());
}

void Game::displayWords() {

    if (!isPaused) {
        if (!wordsList.empty()) {
            if (rand() % 100000 < difficulty_generate) { //częstotliwość of generating words
                std::string randomWord = wordsList[rand() % wordsList.size()];
                float y = 100 +(rand() % (window.getSize().y - 250)); //position
                if (!font.loadFromFile(fonttype)) {
                    std::cerr << "Error loading font file" << std::endl;
                    exit(EXIT_FAILURE);
                }
                words.emplace_back(randomWord, font, y, (rand() % 50) + difficulty_speed, charsize);
            }
        }

        for (auto it = words.begin(); it != words.end();) { //iterujemy po słowach
            auto &word = *it;

            if (word.getPosition().x > window.getSize().x) {
                lives--;
                it = words.erase(it);
            } else {
                word.update(window);
                word.draw(window);
                ++it;
            }

        }

        if (lives <= 0) {
            gameOver = true;
            inputPhrase.clear();
        }
    }

}


void Game::handleInput(char inputChar) {
    isPausedDrawn=false;
    if (!isPaused) {
        if (inputChar == '\b') {
            if (!inputPhrase.empty()) {
                inputPhrase.pop_back();
            }
        } else if (inputChar == ' ') {
            inputPhrase.clear();
        } else if (inputChar == 27) { //escape
        } else {
            inputPhrase += inputChar;
        }

        for (auto it = words.begin(); it != words.end();) {

            auto &word = *it;
            const std::string &wordText = word.getText();

            // Assistant for highlighting longer words



                for (int i = 0; i < wordText.size(); i++) {
                    if (inputPhrase[wordText.size() / 2] == wordText[wordText.size() / 2]
                        && inputPhrase[0] == wordText[0]
                        && inputPhrase[1] == wordText[1]
                        && inputPhrase[2] == wordText[2]) {
                        word.setColor(word, sf::Color(0, 150, 0), 5);
                    } else {
                        word.setColor(word, sf::Color::White, 0);
                    }
                }


            //if we type a correct word it goes adios
            if (wordText == inputPhrase) {
                it = words.erase(it);
                inputPhrase.clear();
                correctwords++;
                break;
            } else {
                ++it;
            }
        }
    }
}

//assistant funkcje

void Game::returnToMainMenu() {
    MainMenu mainMenu(window);
    mainMenu.run();
}

void Game::resetGame() {
    correctwords = 0;
    this->lives = lives;
    gameOver = false;
    words.clear();
}

int Game::correctWordCount() {
    return correctwords;
}

void Game::counters() {
//counter of correct words display
        gui.setWordCounter(correctWordCount());
        sf::Text wordCounterText = gui.getWordCounterText();
        window.draw(wordCounterText);
//lives display
        gui.setLivesCounter(lives);
        sf::Text livesCounterText = gui.getLivesCounterText();
        window.draw(livesCounterText);
//input display
        gui.setUserInput(inputPhrase);
        sf::Text userInputText = gui.getUserInputText();
        window.draw(userInputText);

}

void Game::setDifficulty(long time, int lives, int speed, int generate, int correctwords2) {
    difficulty_speed = speed;
    difficulty_generate = generate;
    timer.setTimer(time);
    this->lives = lives;
    correctwords=correctwords2;
}

void Game::drawPauseScreen() {

    sf::Font font1;
    if (!font1.loadFromFile("../Fonts/arial.ttf")) {
      std::cerr<<"error loading font";
    }
    sf::RectangleShape pauseOverlay(sf::Vector2f(window.getSize().x, window.getSize().y));
    pauseOverlay.setFillColor(sf::Color(0, 0, 0, 150)); // Kolor (R, G, B, A), gdzie A oznacza przezroczystość
    window.draw(pauseOverlay);


    sf::Text pausedText("Paused", font1, 50);
    pausedText.setFillColor(sf::Color::White);
    pausedText.setPosition(window.getSize().x / 2 - pausedText.getGlobalBounds().width / 2, 300);
    window.draw(pausedText);

    sf::Text restartText("Press F5 to return to main menu", font1, 20);
    restartText.setFillColor(sf::Color::White);
    restartText.setPosition(window.getSize().x / 2 - restartText.getGlobalBounds().width / 2, 360);
    window.draw(restartText);
    isPausedDrawn=true;

    sf::Text saveText("Press F6 to save your game", font1, 20);
    saveText.setFillColor(sf::Color::White);
    saveText.setPosition(window.getSize().x / 2 - saveText.getGlobalBounds().width / 2, 390);
    window.draw(saveText);


    window.display();
}

void Game::displaySavedGame() {
    drawPauseScreen();
    if (!font.loadFromFile("../Fonts/arial.ttf")) {
        std::cerr << "error loading font";
    }
    sf::Text gameSavedText("Game saved!", font, 20);
    gameSavedText.setFillColor(sf::Color(10, 120, 200));
    gameSavedText.setPosition(window.getSize().x / 2 - gameSavedText.getGlobalBounds().width / 2, 420);
    window.draw(gameSavedText);

    window.display();
}

void Game::saveGameToFile() {
    std::ofstream saveFile("../Files/SaveGame.txt");
    if (!saveFile.is_open()) {
        std::cerr << "Error opening save file";
        return;
    }
    saveFile << "CorrectWords:" << correctwords << std::endl;
    saveFile << "Lives:" << lives << std::endl;
    saveFile << "Timer:" << timer.getTime() << std::endl;
    saveFile << "Font:" << fonttype << std::endl;
    saveFile << "Size:" << charsize << std::endl;
    saveFile << "Generate:" <<difficulty_generate << std::endl;
    saveFile << "Speed:"<<difficulty_speed<<std::endl;
    saveFile.close();
}


void Game::setCharsize(int charsize) {
    Game::charsize = charsize;
}

void Game::setFonttype(const std::string &fonttype) {
    Game::fonttype = fonttype;
}




