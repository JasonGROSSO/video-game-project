#include <iostream>
#include "player.hpp" 

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Super Chicken Boy!");

    Player player(sf::Vector2f(100, 100), sf::Vector2f(50, 50), 0.2f, 30.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        player.handleMovement(window);
        player.draw(window);

        window.display();
    }

    return 0;
}