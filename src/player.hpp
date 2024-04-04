#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class Player {

public:
    sf::RectangleShape shape;
    float speed;
    float gravity;
    float acceleration = 2.0f;
    bool isJumping;
    float JumpHeight = 300.0f;

    Player(sf::Vector2f position, sf::Vector2f size, float speed, float gravity)
        : shape(size), speed(speed), gravity(gravity), isJumping(false) {
        shape.setPosition(position);
    }

void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
}; 

#endif