#include <iostream>
#include "player.hpp"
#include "wall.hpp"

using namespace sf;

int collisions(FloatRect playerBounds, FloatRect wallBounds);

int main() {
    const int GRID_SIZE = 20;
    const int WINDOW_WIDTH = GRID_SIZE * 30;
    const int WINDOW_HEIGHT = GRID_SIZE * 50;
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Chicken Boy!");

    Player player(Vector2f(GRID_SIZE * 4, GRID_SIZE * 48), Vector2f(GRID_SIZE - 5, GRID_SIZE - 5), 0.035f);
    Vector2f velocity;
    FloatRect nextPos;

    Walls wall;
    wall.setWalls();

    const float GRAVITY = 0.0001f; // Define gravity constant
    const float JUMP_VELOCITY = -0.16f; // Define jump velocity

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        velocity.x = 0.f;
        // movements -----------------------
        if (Keyboard::isKeyPressed(Keyboard::Up) && !player.isJumping) {
            // Jump if not already jumping
            player.isJumping = true;
            velocity.y = JUMP_VELOCITY; // Set vertical velocity to jump velocity
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            velocity.x = -player.maxSpeed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            velocity.x = player.maxSpeed;
        }

        for (auto &wall : wall.walls) {
            FloatRect playerBounds = player.shape.getGlobalBounds();
            FloatRect wallBounds = wall.getGlobalBounds();

            nextPos = playerBounds;
            nextPos.top += velocity.y;
            nextPos.left += velocity.x;

            if (wallBounds.intersects(nextPos)) {
                if (playerBounds.top > wallBounds.top
                && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left) {
                    player.shape.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
                }
                // bottom
                else if (playerBounds.top < wallBounds.top
                && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left) {
                    velocity.y = 0.f;
                    player.shape.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
                    player.isJumping = false;
                }
                // left
                else if (playerBounds.left > wallBounds.left
                && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
                && playerBounds.top < wallBounds.top + wallBounds.height
                && playerBounds.top + playerBounds.height > wallBounds.top) {
                    velocity.x = 0.f;
                    player.shape.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
                }
                // right
                else if (playerBounds.left < wallBounds.left
                && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
                && playerBounds.top < wallBounds.top + wallBounds.height
                && playerBounds.top + playerBounds.height > wallBounds.top) {
                    velocity.x = 0.f;
                    player.shape.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
                }
            }
        }

        // Apply gravity
        velocity.y += GRAVITY;

        player.shape.move(velocity);


        // screen collisions ----------------
        //  top
        if (player.shape.getPosition().y < 0) {
            player.shape.setPosition(player.shape.getPosition().x, 0.f);
        }
        // bottom
        if (player.shape.getPosition().y + player.shape.getGlobalBounds().height > WINDOW_HEIGHT) {
            player.shape.setPosition(player.shape.getPosition().x, WINDOW_HEIGHT - player.shape.getGlobalBounds().height);
            player.isJumping = false;
        }
        // left
        if (player.shape.getPosition().x < 0) {
            player.shape.setPosition(0.f, player.shape.getPosition().y);
        }
        // right
        if (player.shape.getPosition().x + player.shape.getGlobalBounds().width > WINDOW_WIDTH) {
            player.shape.setPosition(WINDOW_WIDTH - player.shape.getGlobalBounds().width, player.shape.getPosition().y);
        }

        // display everything
        window.clear();

        for (auto &i : wall.walls) {
            window.draw(i);
        }
        player.draw(window);

        window.display();
    }

    return 0;
}
