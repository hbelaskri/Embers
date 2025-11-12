#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(sf::Vector2u windowSize);

    Player();

    void handleInput();
    void update(float dt);
    void draw(sf::RenderWindow& window);

    // Accesseurs pour collision
    sf::Vector2f getPosition() const { return sprite.getPosition(); }
    sf::FloatRect getGlobalBounds() const { return sprite.getGlobalBounds(); }
    sf::FloatRect getBounds() const { return rect.getGlobalBounds(); }

    // Déplacement direct (utile pour Level2)
    void move(const sf::Vector2f& offset) { sprite.move(offset); }

    // Ajoutez cette méthode à la classe Player
    sf::CircleShape& getSprite() { return shape; }
    const sf::CircleShape& getSprite() const { return shape; }
    void setRadius(float radius) {
        shape.setRadius(radius);
    }

    // Ajoutez cette méthode publique à la classe Player
    void setFillColor(const sf::Color& color) {
        shape.setFillColor(color);
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape rect;
    sf::CircleShape shape; // Assurez-vous que la classe Player possède un membre sf::CircleShape nommé 'shape'
    sf::Vector2i frameSize = { 32, 48 }; // taille d'une frame
    float speed = 200.f; // vitesse en pixels/s
};

