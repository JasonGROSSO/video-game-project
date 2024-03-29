#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp" 
#include "wall.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Super Chicken Boy!");

    Player player(sf::Vector2f(100, 100), sf::Vector2f(50, 50), 0.2f, 30.f);

    std::vector<Wall> walls;

    // Create a wall at position (200, 200) with size (50, 50)
    Wall wall1(sf::Vector2f(200, 200), sf::Vector2f(50, 50));
    walls.push_back(wall1);

    // Create another wall at a different position and with a different size
    Wall wall2(sf::Vector2f(300, 300), sf::Vector2f(100, 100));
    walls.push_back(wall2);

    // ... add more walls as needed ...

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        window.clear();

        // Draw all walls
        for (const Wall& wall : walls) {
            wall.draw(window);
        }

        player.handleMovement(window, dt, walls);
        player.draw(window);

        window.display();
    }

    return 0;
}