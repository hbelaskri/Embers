

#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include <string>

class Game;

class Menu : public State {
public:
    Menu(Game& game);

    void handleEvent(const sf::Event& ev) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    Game& gameRef;
    sf::Font font;
    sf::Text titleText;
    sf::Text instrText;
    sf::Text missionText;
    sf::Text level2Text; // Pour accéder directement au niveau 2
};
