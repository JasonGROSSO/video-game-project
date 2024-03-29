#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(sf::Vector2f position, sf::Vector2f size, float speed, float gravity)
        : shape(size), speed(speed), gravity(gravity), velocity(0) {
        shape.setPosition(position);
    }

void handleMovement(sf::RenderWindow& window, float dt, const std::vector<Wall>& walls) {
    sf::Vector2f nextPosition;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        nextPosition = shape.getPosition() - sf::Vector2f(speed, 0);
        if (nextPosition.x > 0 && !checkCollision(nextPosition, walls))
            shape.move(-speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        nextPosition = shape.getPosition() + sf::Vector2f(speed, 0);
        if (nextPosition.x < window.getSize().x - shape.getSize().x && !checkCollision(nextPosition, walls))
            shape.move(speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        nextPosition = shape.getPosition() - sf::Vector2f(0, speed);
        if (nextPosition.y > 0 && !checkCollision(nextPosition, walls))
            shape.move(0, -speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        nextPosition = shape.getPosition() + sf::Vector2f(0, speed);
        if (nextPosition.y < window.getSize().y - shape.getSize().y && !checkCollision(nextPosition, walls))
            shape.move(0, speed);
    }

    // Apply gravity
    velocity += gravity * dt;  // Update velocity
    float displacement = velocity * dt; // Calculate displacement
    nextPosition = shape.getPosition() + sf::Vector2f(0, displacement);
    if (!checkCollision(nextPosition, walls)) // Check collision before moving
        shape.move(0, displacement); // Move the shape

    // If the shape reaches the bottom, stop it
    if (shape.getPosition().y + shape.getSize().y >= window.getSize().y) {
        shape.setPosition(shape.getPosition().x, window.getSize().y - shape.getSize().y);
        velocity = 0; // Stop the shape
    }
}

bool checkCollision(sf::Vector2f position, const std::vector<Wall>& walls) {
    sf::FloatRect playerBounds(position, shape.getSize());
    for (const Wall& wall : walls) {
        if (wall.getBounds().intersects(playerBounds))
            return true;
    }
    return false;
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