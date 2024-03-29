#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "wall.hpp"

class Player {
public:
    sf::RectangleShape shape;
    float speed;
    float gravity;
    sf::Vector2f velocity;
    bool isJumping;
    float jumpHeight = 300.0f;

// public:
//     Player(sf::Vector2f position, sf::Vector2f size, float speed, float gravity)
//         : shape(size), speed(speed), gravity(gravity), velocity(0, 0), isJumping(false) {
//         shape.setPosition(position);
//         shape.setFillColor(sf::Color::Green);
//     }

void handleMovement(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (shape.getPosition().x > 0)
                shape.move(-speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (shape.getPosition().x < window.getSize().x - shape.getSize().x)
                shape.move(speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isJumping) {
            // Only jump if not already jumping
            isJumping = true;
            velocity = -sqrt(2.0f * gravity * jumpHeight);
        }

void draw(sf::RenderWindow& window) const {
        window.draw(shape);
    }

    // Apply gravity
    velocity += gravity * 0.001;  // Update velocity
    float displacement = velocity * 0.001; // Calculate displacement
    nextPosition = shape.getPosition() + sf::Vector2f(0, displacement);
    if (!checkCollision(nextPosition, walls)) // Check collision before moving
        shape.move(0, displacement); // Move the shape

    // If the shape reaches the bottom, stop it
    if (shape.getPosition().y + shape.getSize().y >= window.getSize().y) {
        shape.setPosition(shape.getPosition().x, window.getSize().y - shape.getSize().y);
        velocity = 0; // Stop the shape
        isJumping = false;
    }
}

bool checkCollision(sf::Vector2f nextPosition, std::vector<Wall>& walls) {
    sf::FloatRect playerBounds(position, shape.getSize());
    for (const Wall& wall : walls) {
        if (wall.getBounds().intersects(playerBounds))
            return true;
    }
    return false;
}

private:
    sf::RectangleShape shape;
    float speed;
    float gravity;
    float velocity;
    bool isJumping;
    float jumpHeight = 300.0f;
}; 

#endif