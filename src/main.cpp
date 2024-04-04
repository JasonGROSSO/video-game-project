#include <iostream>
#include "player.hpp"
#include "wall.hpp"
#include "finish.hpp"

using namespace sf;

int collisions(FloatRect playerBounds, FloatRect wallBounds);

int main() {
    const int GRID_SIZE = 20;
    const int WINDOW_WIDTH = GRID_SIZE * 30;
    const int WINDOW_HEIGHT = GRID_SIZE * 50;
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Chicken Boy!");
    window.setFramerateLimit(60);

    Player player(Vector2f(GRID_SIZE * 4, GRID_SIZE * 48), Vector2f(GRID_SIZE - 5, GRID_SIZE - 5), 6.f/*0.06f*/);
    Vector2f velocity;
    velocity.y = 0.f;
    velocity.x = 0.f;
    Vector2f speed;
    speed.y = 0.f;
    speed.x = 0.f;
    FloatRect nextPos;

    Walls wall;
    wall.setWalls();

    Finish finish;
    finish.setFinish();

    Finish finish;
    finish.setFinish();

    const float GRAVITY = 0.9f; // Define gravity constant
    const float JUMP_VELOCITY = -16.f; // Define jump velocity

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                window.close();
            }
        }

        // movements -----------------------
        if (Keyboard::isKeyPressed(Keyboard::Up) && !player.isJumping) {
            // Jump if not already jumping
            player.isJumping = true;
            velocity.y = JUMP_VELOCITY; // Set vertical velocity to jump velocity
            if (Keyboard::isKeyPressed(Keyboard::Left) && player.onWall) {
                speed.x += 4.6f;
                velocity.x = speed.x;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right) && player.onWall) {
                speed.x -= 4.6f;
                velocity.x = speed.x;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            if (-player.maxSpeed >= speed.x) {
                velocity.x = -player.maxSpeed;
            }
            else if (speed.x > 0) {
                speed.x -= player.inertia;
                velocity.x = speed.x;
            }
            else {
                speed.x -= player.acceleration;
                velocity.x = speed.x;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            if (player.maxSpeed <= speed.x) {
                velocity.x = player.maxSpeed;
            }
            else if (speed.x < 0) {
                speed.x += player.inertia;
                velocity.x = speed.x;
            }
            else {
                speed.x += player.acceleration;
                velocity.x = speed.x;
            }
        }
        if (!Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right)) {
            if (speed.x < 0) {
                speed.x += player.inertia;
                if (speed.x >= 0) {
                    velocity.x = 0.f;
                }
                else {
                    velocity.x = speed.x;
                }
            }
            if (speed.x > 0) {
                speed.x -= player.inertia;
                if (speed.x <= 0) {
                    velocity.x = 0.f;
                }
                else {
                    velocity.x = speed.x;
                }
            }
        }

        // wall collisions
        for (auto &wall : wall.walls) {
            FloatRect playerBounds = player.shape.getGlobalBounds();
            FloatRect wallBounds = wall.getGlobalBounds();

            nextPos = playerBounds;
            nextPos.top += velocity.y;
            nextPos.left += velocity.x;

            if (wallBounds.intersects(nextPos)) {
                // top
                if (playerBounds.top > wallBounds.top
                && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left) {
                    player.shape.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
                    player.onWall = false;
                }
                // bottom
                else if (playerBounds.top < wallBounds.top
                && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left) {
                    velocity.y = 0.f;
                    player.shape.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
                    player.isJumping = false;
                    player.onWall = false;
                }
                // left
                else if (playerBounds.left > wallBounds.left
                && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
                && playerBounds.top < wallBounds.top + wallBounds.height
                && playerBounds.top + playerBounds.height > wallBounds.top) {
                    speed.x = 0.f;
                    velocity.x = speed.x;
                    player.shape.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
                    player.isJumping = false;
                    player.onWall = true;
                }
                // right
                else if (playerBounds.left < wallBounds.left
                && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
                && playerBounds.top < wallBounds.top + wallBounds.height
                && playerBounds.top + playerBounds.height > wallBounds.top) {
                    speed.x = 0.f;
                    velocity.x = speed.x;
                    player.shape.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
                    player.isJumping = false;
                    player.onWall = true;
                }
                else {
                    player.onWall = false;
                }
            }
        }

        if(player.shape.getGlobalBounds().intersects(finish.shape.getGlobalBounds())) {
            
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
        window.draw(finish.shape);
        player.draw(window);

        window.display();
    }

    return 0;
}
