#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>

class Level2End : public State {
public:
    Level2End(int finalScore);

    void handleEvent(const sf::Event& ev) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::Font font;
    sf::Text missionText;
    int score;
};
