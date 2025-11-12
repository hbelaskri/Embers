//#include "Game.h"
//#include "State.h"
//#include "Menu.h" // Ou Level si tu veux passer direct au niveau
//#include <iostream>
//
//Game::Game()
//    : window(sf::VideoMode({ 800, 600 }), "Embers - Les Dernieres Lueurs"),
//    introText(introText)
//{
//    window.setFramerateLimit(60);
//
//    // Charge police
//    if (!font.openFromFile("assets/fonts/arial.ttf")) {
//        std::cerr << "Erreur : impossible de charger la police\n";
//    }
//
//    // Configure texte d’intro
//    introText.setFont(font);
//    introText.setString(
//        "Bienvenue sur Embers !\n\n"
//        "Tu es un survivant dans un monde en flammes.\n"
//        "Évite les ennemis et survive 5 minutes !\n\n"
//        "Appuie sur ENTREE pour commencer..."
//    );
//    introText.setCharacterSize(24);
//    introText.setFillColor(sf::Color::White);
//    introText.setPosition({ 50.f, 200.f });
//}
//
//Game::~Game() = default;
//
//void Game::processEvents()
//{
//    // Correction : utiliser std::optional<sf::Event> pour pollEvent
//    while (auto event = window.pollEvent()) { // event est un std::optional<sf::Event>
//        if (event->is<sf::Event::Closed>())
//            window.close();
//
//        if (inIntro && event->is<sf::Event::KeyPressed>()) {
//            const auto* keyEv = event->getIf<sf::Event::KeyPressed>();
//            if (keyEv && keyEv->code == sf::Keyboard::Key::Enter) {
//                inIntro = false;
//                currentState = std::make_unique<Menu>(*this);
//            }
//        }
//        else if (!inIntro && currentState) {
//            currentState->handleEvent(*event);
//        }
//    }
//}
//
//void Game::update(float dt)
//{
//    if (!inIntro && currentState)
//        currentState->update(dt);
//}
//
//void Game::render()
//{
//    window.clear(sf::Color(10, 10, 10));
//
//    if (inIntro) {
//        window.draw(introText);
//    }
//    else if (currentState) {
//        currentState->draw(window);
//    }
//
//    window.display();
//}
//
//void Game::run()
//{
//    while (window.isOpen()) {
//        processEvents();
//        float dt = deltaClock.restart().asSeconds();
//        update(dt);
//        render();
//    }
//}
//
//void Game::changeState(std::unique_ptr<State> newState)
//{
//    currentState = std::move(newState);
//}

#include "Game.h"
#include "State.h"
#include "Menu.h" // Ou Level si tu veux passer direct au niveau
#include <iostream>

Game::Game()
    : window(sf::VideoMode({ 800, 600 }), "Embers - Les Dernieres Lueurs"),
    introText(introText)
{
    window.setFramerateLimit(60);

    // Charge police
    if (!font.openFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Erreur : impossible de charger la police\n";
    }

    // Configure texte d’intro
    introText.setFont(font);
    introText.setString(
        "Bienvenue sur Embers !\n\n"
        "Tu es un survivant dans un monde en flammes.\n"
        "Évite les ennemis et survive 5 minutes !\n\n"
        "Appuie sur ENTREE pour commencer..."
    );
    introText.setCharacterSize(24);
    introText.setFillColor(sf::Color::White);
    introText.setPosition({ 50.f, 200.f });
}

Game::~Game() = default;

void Game::processEvents()
{
    // Correction : utiliser std::optional<sf::Event> pour pollEvent
    while (auto event = window.pollEvent()) { // event est un std::optional<sf::Event>
        if (event->is<sf::Event::Closed>())
            window.close();

        if (inIntro && event->is<sf::Event::KeyPressed>()) {
            const auto* keyEv = event->getIf<sf::Event::KeyPressed>();
            if (keyEv && keyEv->code == sf::Keyboard::Key::Enter) {
                inIntro = false;
                currentState = std::make_unique<Menu>(*this);
            }
        }
        else if (!inIntro && currentState) {
            currentState->handleEvent(*event);
        }
    }
}

void Game::update(float dt)
{
    if (!inIntro && currentState)
        currentState->update(dt);
}

void Game::render()
{
    window.clear(sf::Color(10, 10, 10));

    if (inIntro) {
        window.draw(introText);
    }
    else if (currentState) {
        currentState->draw(window);
    }

    window.display();
}

void Game::run()
{
    while (window.isOpen()) {
        processEvents();
        float dt = deltaClock.restart().asSeconds();
        update(dt);
        render();
    }
}

void Game::changeState(std::unique_ptr<State> newState)
{
    currentState = std::move(newState);
}
