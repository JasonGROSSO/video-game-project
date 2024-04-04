#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class Player {

public:
    sf::RectangleShape shape;
    float maxSpeed;
    float speed;
    float acceleration = 2.0f;
    bool isJumping;
    float jumpHeight = 300.0f;

    Player(sf::Vector2f position, sf::Vector2f size, float speed)
        : shape(size), maxSpeed(speed), speed(speed), isJumping(false) {
        shape.setPosition(position);
    }

void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
}; 

#endif