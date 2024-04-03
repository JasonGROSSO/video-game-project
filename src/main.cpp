#include <iostream>
#include "player.hpp" 

using namespace sf;

int collisions(FloatRect playerBounds, FloatRect wallBounds);

int main() {
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 800;
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Chicken Boy!");

    Player player(Vector2f(600, 600), Vector2f(50, 50), 0.1f, 30.f);
    Vector2f velocity;
    FloatRect nextPos;

    std::vector<RectangleShape> walls1; Wall wall1(Vector2f(800, 575), Vector2f(200, 200)); walls1.push_back(wall1.shape);
    std::vector<RectangleShape> walls2; Wall wall2(Vector2f(0, 400), Vector2f(200, 200)); walls2.push_back(wall2.shape);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        velocity.y = 0.f;
        velocity.x = 0.f;
        // movements -----------------------
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            velocity.y = -player.speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            velocity.y = player.speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            velocity.x = -player.speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            velocity.x = player.speed;
        }

        for (auto &wall : walls1) {
            FloatRect playerBounds = player.shape.getGlobalBounds();
            FloatRect wallBounds = wall.getGlobalBounds();

            nextPos = playerBounds;
            nextPos.top += velocity.y;
            nextPos.left += velocity.x;

            if (wallBounds.intersects(nextPos)) {
                switch (collisions(playerBounds, wallBounds)) {
                    case 1:
                        velocity.y = 0.f;
                        player.shape.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
                        break;
                    case 2:
                        velocity.y = 0.f;
                        player.shape.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
                        break;
                    case 3:
                        velocity.x = 0.f;
                        player.shape.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
                        break;
                    case 4:
                        velocity.x = 0.f;
                        player.shape.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
                        break;
                }
            }
        }
        for (auto &wall : walls2) {
            FloatRect playerBounds = player.shape.getGlobalBounds();
            FloatRect wallBounds = wall.getGlobalBounds();

            nextPos = playerBounds;
            nextPos.top += velocity.y;
            nextPos.left += velocity.x;

            if (wallBounds.intersects(nextPos)) {
                switch (collisions(playerBounds, wallBounds)) {
                    case 1:
                        velocity.y = 0.f;
                        player.shape.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
                        break;
                    case 2:
                        velocity.y = 0.f;
                        player.shape.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
                        break;
                    case 3:
                        velocity.x = 0.f;
                        player.shape.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
                        break;
                    case 4:
                        velocity.x = 0.f;
                        player.shape.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
                        break;
                }
            }
        }

        player.shape.move(velocity);


        // screen collisions ----------------
        //  top
        if (player.shape.getPosition().y < 0) {
            player.shape.setPosition(player.shape.getPosition().x, 0.f);
        }
        // bottom
        if (player.shape.getPosition().y + player.shape.getGlobalBounds().height > WINDOW_HEIGHT) {
            player.shape.setPosition(player.shape.getPosition().x, WINDOW_HEIGHT - player.shape.getGlobalBounds().height);
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

        wall1.draw(window);
        wall2.draw(window);
        player.draw(window);

        window.display();
    }

    return 0;
}

int collisions(FloatRect playerBounds, FloatRect wallBounds) {
    // top
    if (playerBounds.top > wallBounds.top
    && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
    && playerBounds.left < wallBounds.left + wallBounds.width
    && playerBounds.left + playerBounds.width > wallBounds.left) {
        return 1;
    }
    // bottom
    else if (playerBounds.top < wallBounds.top
    && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
    && playerBounds.left < wallBounds.left + wallBounds.width
    && playerBounds.left + playerBounds.width > wallBounds.left) {
        return 2;
    }
    // left
    else if (playerBounds.left > wallBounds.left
    && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
    && playerBounds.top < wallBounds.top + wallBounds.height
    && playerBounds.top + playerBounds.height > wallBounds.top) {
        return 3;
    }
    // right
    else if (playerBounds.left < wallBounds.left
    && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
    && playerBounds.top < wallBounds.top + wallBounds.height
    && playerBounds.top + playerBounds.height > wallBounds.top) {
        return 4;
    }
}

//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//            if (player.shape.getPosition().x <= 0){
//                player.shape.move(0, 0);
//            }
//            else if (player.shape.getGlobalBounds().intersects(wall2.shape.getGlobalBounds()) && player.shape.getPosition().y + player.shape.getSize().y - 1 > wall2.shape.getPosition().y) {
//                player.shape.move(0, 0);
//            }
//            else {
//                player.shape.move(-player.speed, 0);
//            }
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//            if (player.shape.getPosition().x >= window.getSize().x - player.shape.getSize().x) {
//                player.shape.move(0, 0);
//            }
//            else if (player.shape.getGlobalBounds().intersects(wall1.shape.getGlobalBounds()) && player.shape.getPosition().y + player.shape.getSize().y - 1 > wall1.shape.getPosition().y) {
//                player.shape.move(0, 0);
//            }
//            else {
//                player.shape.move(player.speed, 0);
//            }
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !player.isJumping) {
//            player.isJumping = true;
//            if(!player.shape.getGlobalBounds().intersects(wall1.shape.getGlobalBounds()) || !player.shape.getGlobalBounds().intersects(wall2.shape.getGlobalBounds())) {
//                player.velocity = -sqrt(2.0f * player.gravity * player.JumpHeight);
//            }
//        }
//
//        // Apply gravity
//        player.velocity += player.gravity * 0.001;  // Update velocity
//        float displacement = player.velocity * 0.001; // Calculate displacement
//        player.shape.move(0, displacement); // Move the shape
//        // If the shape reaches the bottom, stop it
//        if (player.shape.getPosition().y + player.shape.getSize().y >= window.getSize().y || player.shape.getGlobalBounds().intersects(wall1.shape.getGlobalBounds()) || player.shape.getGlobalBounds().intersects(wall2.shape.getGlobalBounds())) {
//                player.velocity = 0; // Stop the shape
//         //       player.isJumping = false;
//        }//
