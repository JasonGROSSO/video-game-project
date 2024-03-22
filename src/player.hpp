#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(sf::Vector2f position, sf::Vector2f size, float speed, float gravity)
        : shape(size), speed(speed), gravity(gravity), velocity(0) {
        shape.setPosition(position);
    }

    void handleMovement(sf::RenderWindow& window, float dt) {
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

        // Apply gravity
        velocity += gravity * dt;  // Update velocity
        float displacement = velocity * dt; // Calculate displacement
        shape.move(0, displacement); // Move the shape

        // If the shape reaches the bottom, stop it
        if (shape.getPosition().y + shape.getSize().y >= window.getSize().y) {
            shape.setPosition(shape.getPosition().x, window.getSize().y - shape.getSize().y);
            velocity = 0; // Stop the shape
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

private:
    sf::RectangleShape shape;
    float speed;
    float gravity;
    float velocity;
}; 

#endif