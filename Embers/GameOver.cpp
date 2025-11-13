
#include "GameOver.h"
#include "Level1.h"
#include <iostream>

GameOver::GameOver(Game& game) : gameRef(game), message(font)
{
    if (!font.openFromFile("assets/fonts/arial.ttf"))
        std::cerr << "Erreur chargement font GameOver\n";

    message.setFont(font);
    message.setString("Vous avez été touché par un carré rouge !\nAppuyez sur ENTREE pour recommencer.");
    message.setCharacterSize(24);
    message.setFillColor(sf::Color::Red);
    message.setPosition({ 50.f, 200.f });
}

void GameOver::handleEvent(const sf::Event& ev)
{
    if (ev.is<sf::Event::KeyPressed>()) {
        auto keyEv = ev.getIf<sf::Event::KeyPressed>();
        if (keyEv && keyEv->code == sf::Keyboard::Key::Enter) {
            sf::Vector2u windowSize = gameRef.getWindow().getSize();
            gameRef.changeState(std::make_unique<Level1>(gameRef, windowSize));
        }
    }
}

void GameOver::update(float) {}

void GameOver::draw(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
    window.draw(message);
    window.display();
}
