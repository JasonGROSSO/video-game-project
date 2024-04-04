#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class Player {

public:
    sf::RectangleShape shape;
    float maxSpeed;
    float gravity = 0.003f;
    float acceleration = 0.000020f;
    float inertia = 0.00004f;
    bool isJumping;
    float jumpHeight = 250.0f;

    Player(sf::Vector2f position, sf::Vector2f size, float speed)
        : shape(size), maxSpeed(speed), isJumping(true) {
        shape.setPosition(position);
    }

void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
}; 

#endif