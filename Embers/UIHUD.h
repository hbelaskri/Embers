//#pragma once
//#include <SFML/Graphics.hpp>
//
//class UIHUD {
//public:
//    UIHUD() {}
//    void update(float timeLeft, int enemyCount) {}
//    void draw(sf::RenderWindow& window) {}
//};


//#pragma once
//#include <SFML/Graphics.hpp>
//
//class UIHUD {
//public:
//    UIHUD();
//
//    void addLight(int amount);       // ajouter des points de lumière
//    void update(float dt);           // <-- Ajout de la méthode update
//    void draw(sf::RenderWindow& window);
//
//private:
//    sf::RectangleShape barBackground;
//    sf::RectangleShape barForeground;
//    float barMaxHeight = 200.f;     // hauteur de la barre verticale
//    int lightScore = 0;             // 0 à 100
//};


#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class UIHUD {
public:
    UIHUD();

    void addLight(int amount);       // ajouter des points de lumière
    void addMessage(const std::string& msg); // ajouter un message narratif
    void update(float dt);           // mise à jour timer et jauge
    void draw(sf::RenderWindow& window);

private:
    // Jauge lumière
    sf::RectangleShape barBackground;
    sf::RectangleShape barForeground;
    float barMaxHeight = 200.f;
    int lightScore = 0;

    // Interface narrative
    std::vector<std::string> messages;
    size_t currentIndex = 0;
    float messageTimer = 0.f;
    float displayInterval = 3.f; // durée d'affichage d'un message
    sf::Font font;
};
