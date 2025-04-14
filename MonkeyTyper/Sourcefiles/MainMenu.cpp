#include "../Headers/MainMenu.hpp"
#include <iostream>
#include <sstream>

MainMenu::MainMenu(sf::RenderWindow& mainWindow) : window(mainWindow), game(window){
    if (!font.loadFromFile("../Fonts/arial.ttf")) {
        std::cerr << "Error loading font\n";
        exit(EXIT_FAILURE);
    }

    if (!mainfont.loadFromFile("../Fonts/royal.otf")) {
        std::cerr << "Error loading font\n";
        exit(EXIT_FAILURE);
    }
    if (!font2.loadFromFile("../Fonts/crown.ttf")) {
        std::cerr << "Error loading font\n";
        exit(EXIT_FAILURE);
    }
    if (!font3.loadFromFile("../Fonts/john.ttf")) {
        std::cerr << "Error loading font\n";
        exit(EXIT_FAILURE);
    }
    if (!font4.loadFromFile("../Fonts/paul.otf")) {
        std::cerr << "Error loading font\n";
        exit(EXIT_FAILURE);
    }
    if (!font5.loadFromFile("../Fonts/second.ttf")) {
        std::cerr << "Error loading font\n";
        exit(EXIT_FAILURE);
    }
//init of Buttons
    title.setFont(mainfont);
    title.setString("Monkey Typer");
    title.setCharacterSize(160);
    title.setOutlineColor(sf::Color::White);
    title.setOutlineThickness(1);
    title.setFillColor(sf::Color(67, 112, 69));
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 80);

    playButton.setFont(font);
    playButton.setString("Play");
    playButton.setCharacterSize(50);
    playButton.setFillColor(sf::Color::White);
    playButton.setPosition(window.getSize().x / 2 - playButton.getGlobalBounds().width / 2, 300);

    easyButton.setFont(font);
    easyButton.setString("Easy");
    easyButton.setCharacterSize(30);
    easyButton.setFillColor(sf::Color::White);
    easyButton.setPosition(window.getSize().x / 2 - easyButton.getGlobalBounds().width / 2, 370);

    mediumButton.setFont(font);
    mediumButton.setString("Medium");
    mediumButton.setCharacterSize(30);
    mediumButton.setFillColor(sf::Color::White);
    mediumButton.setPosition(window.getSize().x / 2 - mediumButton.getGlobalBounds().width / 2, 410);

    hardButton.setFont(font);
    hardButton.setString("Hard");
    hardButton.setCharacterSize(30);
    hardButton.setFillColor(sf::Color::White);
    hardButton.setPosition(window.getSize().x / 2 - hardButton.getGlobalBounds().width / 2, 450);

    infiniteButton.setFont(font);
    infiniteButton.setString("Infinite");
    infiniteButton.setCharacterSize(40);
    infiniteButton.setFillColor(sf::Color::White);
    infiniteButton.setPosition(window.getSize().x / 2 - infiniteButton.getGlobalBounds().width / 2, 500);

    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(40);
    exitButton.setFillColor(sf::Color::White);
    exitButton.setPosition(window.getSize().x / 2 - exitButton.getGlobalBounds().width / 2, 730);

    loadButton.setFont(font);
    loadButton.setString("Load game");
    loadButton.setCharacterSize(40);
    loadButton.setFillColor(sf::Color::White);
    loadButton.setPosition(window.getSize().x / 2 - loadButton.getGlobalBounds().width / 2, 560);

//config buttons

    config.setFont(font);
    config.setString("Config");
    config.setCharacterSize(30);
    config.setFillColor(sf::Color::White);
    config.setPosition(1070,  5);

    fontbutton1.setFont(font);
    fontbutton1.setString("Arial");
    fontbutton1.setCharacterSize(20);
    fontbutton1.setFillColor(sf::Color::White);
    fontbutton1.setPosition(1070,  50);

    fontbutton2.setFont(font2);
    fontbutton2.setString("Crown");
    fontbutton2.setCharacterSize(20);
    fontbutton2.setFillColor(sf::Color::White);
    fontbutton2.setPosition(1070,  80);

    fontbutton3.setFont(font3);
    fontbutton3.setString("John");
    fontbutton3.setCharacterSize(20);
    fontbutton3.setFillColor(sf::Color::White);
    fontbutton3.setPosition(1070,  114);

    fontbutton4.setFont(font4);
    fontbutton4.setString("Paul");
    fontbutton4.setCharacterSize(25);
    fontbutton4.setFillColor(sf::Color::White);
    fontbutton4.setPosition(1070,  137);

    fontbutton5.setFont(font5);
    fontbutton5.setString("Second");
    fontbutton5.setCharacterSize(20);
    fontbutton5.setFillColor(sf::Color::White);
    fontbutton5.setPosition(1070,  170);


    sizebutton1.setFont(font);
    sizebutton1.setString("30");
    sizebutton1.setCharacterSize(15);
    sizebutton1.setFillColor(sf::Color::White);
    sizebutton1.setPosition(1130, 50);

    sizebutton2.setFont(font);
    sizebutton2.setString("45");
    sizebutton2.setCharacterSize(20);
    sizebutton2.setFillColor(sf::Color::White);
    sizebutton2.setPosition(1130, 70);

    sizebutton3.setFont(font);
    sizebutton3.setString("60");
    sizebutton3.setCharacterSize(25);
    sizebutton3.setFillColor(sf::Color::White);
    sizebutton3.setPosition(1130, 95);

    sizebutton4.setFont(font);
    sizebutton4.setString("75");
    sizebutton4.setCharacterSize(30);
    sizebutton4.setFillColor(sf::Color::White);
    sizebutton4.setPosition(1130, 125);

    sizebutton5.setFont(font);
    sizebutton5.setString("90");
    sizebutton5.setCharacterSize(35);
    sizebutton5.setFillColor(sf::Color::White);
    sizebutton5.setPosition(1130, 160);



}

void MainMenu::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}

//starting the game basically(after clicking some buttons) + checking hovers
void MainMenu::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (playButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                isPlayClicked = true;
            }

            if (isPlayClicked) {
                if (easyButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    startGame(0); // Easy mode
                }
                if (mediumButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    startGame(1); // Medium mode
                }
                if (hardButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    startGame(2); // Hard mode
                }
            }
            if (infiniteButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                startGame(3); // Infinite mode
            }
            if (exitButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                window.close();
            }
            if (loadButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                Game game(window);
                game.setDifficulty(readTimerFromSaveGame(), readLivesFromSaveGame(), readSpeedFromSaveGame(), readGenerateFromSaveGame(), readWordsFromSaveGame());
                game.setCharsize(readSizeFromSaveGame());
                game.setFonttype(readFontFromSaveGame());
                game.run();
            }


//config buttons
            if (config.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                isConfigClicked = true;
            }

            if (isConfigClicked) {
                if (fontbutton1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    changefont(0);
                }
                if (fontbutton2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    changefont(1);
                }
                if (fontbutton3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    changefont(2);
                }
                if (fontbutton4.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    changefont(3);
                }
                if (fontbutton5.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    changefont(4);
                }
                if (sizebutton1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    changesize(0);
                }
                if (sizebutton2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    changesize(1);
                }
                if (sizebutton3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    changesize(2);
                }
                if (sizebutton4.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    changesize(3);
                }
                if (sizebutton5.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    changesize(4);
                }
            }


        }
//Hovers
        if (event.type == sf::Event::MouseMoved) {
            if (playButton.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                isPlayHovered = true;
            } else {
                isPlayHovered = false;
            }

            if (easyButton.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                isEasyHovered = true;
            } else {
                isEasyHovered = false;
            }

            if (mediumButton.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                isMediumHovered = true;
            } else {
                isMediumHovered = false;
            }

            if (hardButton.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                isHardHovered = true;
            } else {
                isHardHovered = false;
            }

            if (infiniteButton.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                isInfiniteHovered = true;
            } else {
                isInfiniteHovered = false;
            }

            if (exitButton.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                isExitHovered = true;
            } else {
                isExitHovered = false;
            }

            if (loadButton.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                isLoadHovered = true;
            } else {
                isLoadHovered = false;
            }

            if (config.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                isConfigHovered = true;
            } else {
                isConfigHovered = false;
            }

            if (fontbutton1.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                fb1h = true;
            } else {
                fb1h = false;
            }

            if (fontbutton2.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                fb2h = true;
            } else {
                fb2h = false;
            }

            if (fontbutton3.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                fb3h = true;
            } else {
                fb3h = false;
            }

            if (fontbutton4.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                fb4h = true;
            } else {
                fb4h = false;
            }

            if (fontbutton5.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                fb5h = true;
            } else {
                fb5h = false;
            }

            if (sizebutton1.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                sb1h = true;
            } else {
                sb1h = false;
            }

            if (sizebutton2.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                sb2h = true;
            } else {
                sb2h = false;
            }

            if (sizebutton3.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                sb3h = true;
            } else {
                sb3h = false;
            }

            if (sizebutton4.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                sb4h = true;
            } else {
                sb4h = false;
            }

            if (sizebutton5.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                sb5h = true;
            } else {
                sb5h = false;
            }
        }
    }
}
//drawing
void MainMenu::render() {
    window.clear();

    sf::Texture texture;
    if (!texture.loadFromFile("../Images/background.jpg")) {
        std::cerr<<"Error loading a bg!";
    }

    sf::RectangleShape overlay;
    overlay.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    overlay.setTexture(&texture);
    window.draw(overlay);

//hovers - colors

    window.draw(title);
    window.draw(playButton);
    window.draw(infiniteButton);
    window.draw(exitButton);
    window.draw(config);


    if (isPlayHovered) {
        playButton.setFillColor(sf::Color(67, 112, 69));
    } else {
        playButton.setFillColor(sf::Color::White);
    }
    window.draw(playButton);

    if (isLoadHovered) {
        loadButton.setFillColor(sf::Color(67, 112, 69));
    } else {
        loadButton.setFillColor(sf::Color::White);
    }
    window.draw(loadButton);

    if (isInfiniteHovered) {
        infiniteButton.setFillColor(getRandomColor());
    } else {
        infiniteButton.setFillColor(sf::Color::White);
    }
    window.draw(infiniteButton);

    if (isExitHovered) {
        exitButton.setFillColor(sf::Color(117, 22, 12));
    } else {
        exitButton.setFillColor(sf::Color::White);
    }
    window.draw(exitButton);

    if (isConfigHovered) {
        config.setFillColor(sf::Color(67, 112, 69));
    } else {
        config.setFillColor(sf::Color::White);
    }
    window.draw(config);


    if (isPlayClicked) {
        window.draw(easyButton);
        window.draw(mediumButton);
        window.draw(hardButton);
        if (isEasyHovered) {
            easyButton.setFillColor(sf::Color::Green);
        } else {
            easyButton.setFillColor(sf::Color::White);
        }
        window.draw(easyButton);

        if (isMediumHovered) {
            mediumButton.setFillColor(sf::Color::Yellow);
        } else {
            mediumButton.setFillColor(sf::Color::White);
        }
        window.draw(mediumButton);

        if (isHardHovered) {
            hardButton.setFillColor(sf::Color::Red);
        } else {
            hardButton.setFillColor(sf::Color::White);
        }
        window.draw(hardButton);
    }
//config options
    if(isConfigClicked)
    {
        window.draw(fontbutton1);
        window.draw(fontbutton2);
        window.draw(fontbutton3);
        window.draw(fontbutton4);
        window.draw(fontbutton5);
        window.draw(sizebutton1);
        window.draw(sizebutton2);
        window.draw(sizebutton3);
        window.draw(sizebutton4);
        window.draw(sizebutton5);

        if (fb1h) {
            fontbutton1.setFillColor(sf::Color::Green);
        } else {
            fontbutton1.setFillColor(sf::Color::White);
        }
        window.draw(fontbutton1);
        if (fb2h) {
            fontbutton2.setFillColor(sf::Color::Green);
        } else {
            fontbutton2.setFillColor(sf::Color::White);
        }
        window.draw(fontbutton2);
        if (fb3h) {
            fontbutton3.setFillColor(sf::Color::Green);
        } else {
            fontbutton3.setFillColor(sf::Color::White);
        }
        window.draw(fontbutton3);
        if (fb4h) {
            fontbutton4.setFillColor(sf::Color::Green);
        } else {
            fontbutton4.setFillColor(sf::Color::White);
        }
        window.draw(fontbutton4);
        if (fb5h) {
            fontbutton5.setFillColor(sf::Color::Green);
        } else {
            fontbutton5.setFillColor(sf::Color::White);
        }
        window.draw(fontbutton5);



        if (sb1h) {
            sizebutton1.setFillColor(sf::Color::Green);
        } else {
            sizebutton1.setFillColor(sf::Color::White);
        }
        window.draw(sizebutton1);
        if (sb2h) {
            sizebutton2.setFillColor(sf::Color::Green);
        } else {
            sizebutton2.setFillColor(sf::Color::White);
        }
        window.draw(sizebutton2);
        if (sb3h) {
            sizebutton3.setFillColor(sf::Color::Green);
        } else {
            sizebutton3.setFillColor(sf::Color::White);
        }
        window.draw(sizebutton3);
        if (sb4h) {
            sizebutton4.setFillColor(sf::Color::Green);
        } else {
            sizebutton4.setFillColor(sf::Color::White);
        }
        window.draw(sizebutton4);
        if (sb5h) {
            sizebutton5.setFillColor(sf::Color::Green);
        } else {
            sizebutton5.setFillColor(sf::Color::White);
        }
        window.draw(sizebutton5);

    }
    window.display();
}

void MainMenu::startGame(int difficulty) {

    switch (difficulty) {
        case 0: // Easy
            game.setDifficulty(30, 5, 30, 3, 0);
            break;
        case 1: // Medium
            game.setDifficulty(90, 3, 50, 7, 0);
            break;
        case 2: // Hard
            game.setDifficulty(300, 1, 90, 20, 0);
            break;
        case 3: // Infinite
            game.setDifficulty(999999999, 10, 50, 8,0);
            break;
    }

    game.run();
}


void MainMenu::changefont(int fontnum) {

    switch (fontnum) {
        case 0: game.setFonttype("../Fonts/arial.ttf"); break;
        case 1: game.setFonttype("../Fonts/crown.ttf"); break;
        case 2: game.setFonttype("../Fonts/john.ttf"); break;
        case 3: game.setFonttype("../Fonts/paul.otf"); break;
        case 4: game.setFonttype("../Fonts/second.ttf"); break;
    }
}


void MainMenu::changesize(int size) {

    switch (size) {
        case 0: game.setCharsize(20); break;
        case 1: game.setCharsize(30); break;
        case 2: game.setCharsize(40); break;
        case 3: game.setCharsize(50); break;
        case 4: game.setCharsize(60); break;

    }
}



//assistant funkcje


sf::Color MainMenu::getRandomColor() {
    sf::sleep(sf::milliseconds(70));
    return sf::Color(rand() % 255, rand() % 255, rand() % 255);
}


long MainMenu::readTimerFromSaveGame() {
    std::ifstream file("../Files/SaveGame.txt");
    long time;

    //so basically go through lines and check for keyword and then extract the value that's after ':'
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream stringstream(line);
            std::string key, value;
            if (std::getline(stringstream, key, ':') && std::getline(stringstream, value)) {
                if (key == "Timer") {
                    time = std::stol(value);
                    break;
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file";
    }
    return time;
}

int MainMenu::readLivesFromSaveGame() {
    std::ifstream file("../Files/SaveGame.txt");
    int lives;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream stringstream(line);
            std::string key, value;
            if (std::getline(stringstream, key, ':') && std::getline(stringstream, value)) {
                if (key == "Lives") {
                    lives = std::stoi(value);
                    break;
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file";
    }
    return lives;
}

int MainMenu::readWordsFromSaveGame() {
    std::ifstream file("../Files/SaveGame.txt");
    int words;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream stringstream(line);
            std::string key, value;
            if (std::getline(stringstream, key, ':') && std::getline(stringstream, value)) {
                if (key == "CorrectWords") {
                    words = std::stoi(value);
                    break;
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file";
    }
    return words;
}

std::string MainMenu::readFontFromSaveGame() {
    std::ifstream file("../Files/SaveGame.txt");
    std::string font;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream stringstream(line);
            std::string key, value;
            if (std::getline(stringstream, key, ':') && std::getline(stringstream, value)) {
                if (key == "Font") {
                    font = value;
                    break;
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file";
    }
    return font;
}

int MainMenu::readSizeFromSaveGame() {
    std::ifstream file("../Files/SaveGame.txt");
    int size;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream stringstream(line);
            std::string key, value;
            if (std::getline(stringstream, key, ':') && std::getline(stringstream, value)) {
                if (key == "Size") {
                    size = std::stoi(value);
                    break;
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file";
    }
    return size;
}

int MainMenu::readSpeedFromSaveGame() {
    std::ifstream file("../Files/SaveGame.txt");
    int speed;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream stringstream(line);
            std::string key, value;
            if (std::getline(stringstream, key, ':') && std::getline(stringstream, value)) {
                if (key == "Speed") {
                    speed = std::stoi(value);
                    break;
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file";
    }
    return speed;
}

int MainMenu::readGenerateFromSaveGame() {
    std::ifstream file("../Files/SaveGame.txt");
    int generate;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream stringstream(line);
            std::string key, value;
            if (std::getline(stringstream, key, ':') && std::getline(stringstream, value)) {
                if (key == "Generate") {
                    generate = std::stoi(value);
                    break;
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file";
    }
    return generate;
}