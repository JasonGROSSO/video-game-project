#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <SFML/Graphics.hpp>

void handleMovement(sf::RectangleShape& shape, sf::RenderWindow& window, float speed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (shape.getPosition().x > 0)
            shape.move(-speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (shape.getPosition().x < window.getSize().x - shape.getSize().x)
            shape.move(speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (shape.getPosition().y > 0)
            shape.move(0, -speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (shape.getPosition().y < window.getSize().y - shape.getSize().y)
            shape.move(0, speed);
    }
}

#endif 
