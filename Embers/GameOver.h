
#pragma once
#include "State.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

class GameOver : public State {
public:
    GameOver(Game& game);
    void handleEvent(const sf::Event& ev) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    Game& gameRef;
    sf::Font font;
    sf::Text message;
};
