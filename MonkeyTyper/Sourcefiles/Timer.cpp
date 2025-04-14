
#include "../Headers/Timer.hpp"
#include <iostream>

Timer::Timer(int seconds) : initialSeconds(seconds), secondsRemaining(seconds) {
    if (!font.loadFromFile("../Fonts/SugarRush.ttf")) {
        std::cerr << "Error loading font file" << std::endl;
    }

    timerText.setFont(font);
    timerText.setCharacterSize(24);
    timerText.setFillColor(sf::Color(157, 217, 117));
    timerText.setPosition(1070, 10);
}

void Timer::setTimer(long seconds) {
    initialSeconds = seconds;
    secondsRemaining = seconds;
}

void Timer::update() {
    sf::Time elapsedTime = clock.getElapsedTime();
    if (elapsedTime.asSeconds() >= 1.0f) {
        clock.restart();
        if (secondsRemaining > 0) {
            secondsRemaining--;
        }
    }
}

void Timer::draw(sf::RenderWindow& window) {
    timerText.setString("Time: " + std::to_string(secondsRemaining));
    window.draw(timerText);
}

void Timer::reset() {
    clock.restart();
    secondsRemaining = initialSeconds;
}

int Timer::getTime() const {
return secondsRemaining;
}
