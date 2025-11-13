
#pragma once
#include "State.h"
#include "Player.h"
#include "UIHUD.h"
#include <SFML/Graphics.hpp>

class Level : public State {
public:
    Level(sf::Vector2u windowSize);
    void handleEvent(const sf::Event& ev) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

    bool isCompleted() const { return completed; }

protected:
    Player player;
    UIHUD hud;
    bool completed = false;
};
