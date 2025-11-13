#pragma once
#include "State.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

class Level2End : public State {
public:
    Level2End(Game& game, int finalScore); // maintenant on passe gameRef

    void handleEvent(const sf::Event& ev) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    Game& gameRef;        // référence au Game pour changer d'état
    sf::Font font;
    sf::Text missionText;
    int score;
};

