#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp" 

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Super Chicken Boy!");

    Player player(sf::Vector2f(100, 100), sf::Vector2f(50, 50), 0.1f, 30.f);
    Wall wall1(sf::Vector2f(800, 575), sf::Vector2f(200, 200));
    Wall wall2(sf::Vector2f(0, 400), sf::Vector2f(200, 200));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        wall1.draw(window);
        wall2.draw(window);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (player.shape.getPosition().x <= 0){
                player.shape.move(0, 0);
            }
            else if (player.shape.getGlobalBounds().intersects(wall2.shape.getGlobalBounds()) && player.shape.getPosition().y + player.shape.getSize().y - 1 > wall2.shape.getPosition().y) {
                player.shape.move(0, 0);
            }
            else {
                player.shape.move(-player.speed, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (player.shape.getPosition().x >= window.getSize().x - player.shape.getSize().x) {
                player.shape.move(0, 0);
            }
            else if (player.shape.getGlobalBounds().intersects(wall1.shape.getGlobalBounds()) && player.shape.getPosition().y + player.shape.getSize().y - 1 > wall1.shape.getPosition().y) {
                player.shape.move(0, 0);
            }
            else {
                player.shape.move(player.speed, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !player.isJumping) {
            player.isJumping = true;
            if(!player.shape.getGlobalBounds().intersects(wall1.shape.getGlobalBounds()) || !player.shape.getGlobalBounds().intersects(wall2.shape.getGlobalBounds())) {
                player.velocity = -sqrt(2.0f * player.gravity * player.JumpHeight);
            }
        }

        // Apply gravity
        player.velocity += player.gravity * 0.001;  // Update velocity
        float displacement = player.velocity * 0.001; // Calculate displacement
        player.shape.move(0, displacement); // Move the shape
        // If the shape reaches the bottom, stop it
        if (player.shape.getPosition().y + player.shape.getSize().y >= window.getSize().y || player.shape.getGlobalBounds().intersects(wall1.shape.getGlobalBounds()) || player.shape.getGlobalBounds().intersects(wall2.shape.getGlobalBounds())) {
                player.velocity = 0; // Stop the shape
                player.isJumping = false;
        }
        
        player.draw(window);
        window.display();
    }

    return 0;
}
