
#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(const sf::Vector2f& startPos, float spd); // constructeur avec vitesse
    void update(float dt, const sf::Vector2f& playerPos);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const { return rect.getGlobalBounds(); }
    void move(const sf::Vector2f& offset) { rect.move(offset); }
    sf::Vector2f getPosition() const { return rect.getPosition(); }
    sf::Vector2f getSize() const { return rect.getSize(); } // <-- AJOUT POUR CORRIGER L'ERREUR
    sf::FloatRect getGlobalBounds() const { return rect.getGlobalBounds(); } // Ajout de la méthode getGlobalBounds à la classe Enemy
    sf::RectangleShape shape;

private:
    sf::RectangleShape rect;
    float speed;
};
