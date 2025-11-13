#include "Game.h"
#include "State.h"
#include "Menu.h"
#include <iostream>
#include "Level2End.h"

Game::Game()
    : window(sf::VideoMode({ 800, 600 }), "Embers - Les Dernieres Lueurs"), introText(font)
{
    window.setFramerateLimit(60);

    if (!font.openFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Erreur : impossible de charger la police\n";
    }

    // Texte d’intro
    introText.setFont(font);
    introText.setString(
        " Bienvenue sur Embers : Les Dernières Lueurs \n\n"
        "Tu es le PROTECTEUR de la FLAMME, celui que les ténèbres craignent.\n"
        "Seul toi peux sauver le monde en récoltant et en  diffusant la lumière.\n\n"
        "Les ombres rôdent et cherchent à éteindre l'espoir.\n"
        "Collecte la lumière, diffuse-la et protège chaque étincelle de vie.\n\n"
        "Chaque seconde compte : chaque rayon de lumière peut faire la différence.\n\n"
        "Prépare-toi à relever le défi et deviens le gardien des flammes.\n\n"
        "Appuie sur ENTREE pour commencer ton aventure..."
    );
    introText.setCharacterSize(20);
   
    
  /*  introText.setFillColor(sf::Color(200, 200, 0));
    introText.setOutlineColor(sf::Color(255, 100, 0));*/
    introText.setFillColor(sf::Color(255, 220, 100)); // jaune doux, moins agressif
    introText.setOutlineColor(sf::Color(180, 100, 0));
    introText.setPosition({ 50.f, 100.f });
    introText.setOutlineThickness(2.f);
    introText.setStyle(sf::Text::Bold);
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
                introText.setString(""); // Efface le texte d’intro
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
    window.clear();

    if (inIntro) {
        window.clear(sf::Color(10, 10, 10));
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

sf::RenderWindow& Game::getWindow()
{
    return window;
}
