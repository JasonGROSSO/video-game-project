#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cmath>

class Player {
public:
    const int GRID_SIZE = 20;
    const sf::Vector2f spawnPoint = sf::Vector2f(GRID_SIZE * 4, GRID_SIZE * 48);

    sf::RectangleShape shape;
    sf::Texture playerTexture;
    float maxSpeed = 6.f;
    float acceleration = 0.2f;
    float inertia = 0.4f;
    bool isJumping = true;
    bool onWall = true;

    void setPlayer() {
        playerTexture.loadFromFile("img/chicken.png");
        shape.setTexture(&playerTexture);
        shape.setPosition(spawnPoint);
        shape.setSize(sf::Vector2f(GRID_SIZE - 5, GRID_SIZE - 5));
    }

void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
}; 

#endif