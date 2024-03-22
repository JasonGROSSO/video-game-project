#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp" 

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Super Chicken Boy!");

    Player player(sf::Vector2f(100, 100), sf::Vector2f(50, 50), 0.2f, 30.f);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        window.clear();

        player.handleMovement(window, dt);
        player.draw(window);

        window.display();
    }

    return 0;
}
