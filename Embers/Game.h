//#pragma once
//#include <SFML/Graphics.hpp>
//#include <memory>
//#include "State.h"
//
//class Menu; // Forward declaration
//
//class Game {
//public:
//    Game();
//    ~Game();
//
//   
//    void changeState(State* newState);
//
//    void run();
//    void processEvents();
//    void update(float dt);
//    void render();
//    void changeState(std::unique_ptr<State> newState);
//    sf::RenderWindow& getWindow(); // Ajout de la méthode manquante
//
//private:
//    sf::RenderWindow window;
//    sf::Font font;
//    sf::Text introText; // Ajout de la déclaration manquante
//    sf::Clock deltaClock;
//    bool inIntro = true;
//    std::unique_ptr<State> currentState;
//};

#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "State.h"

class Menu; // Forward declaration

class Game {
public:
    Game();
    ~Game();

    void run();
    void processEvents();
    void update(float dt);
    void render();
    void changeState(std::unique_ptr<State> newState);
    sf::RenderWindow& getWindow(); // Ajout de la méthode manquante

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text introText; // Ajout de la déclaration manquante
    sf::Clock deltaClock;
    bool inIntro = true;
    std::unique_ptr<State> currentState;
};
