#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class Player {

public:
    sf::RectangleShape shape;
    float maxSpeed;
    float acceleration = 0.2f/*0.00002f*/;
    float inertia = 0.4f/*0.00004f*/;
    bool isJumping;
    bool onWall;

    Player(sf::Vector2f position, sf::Vector2f size, float speed)
        : shape(size), maxSpeed(speed), isJumping(true), onWall(false) {
        shape.setPosition(position);
    }

void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
}; 

#endif