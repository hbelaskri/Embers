#pragma once
#include <SFML/Graphics.hpp>

class State {
public:
    virtual ~State() = default;
    virtual void handleEvent(const sf::Event& ev) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};
