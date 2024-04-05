#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "player.hpp"
#include "wall.hpp"
#include "spikes.hpp"
#include "finish.hpp"

using namespace sf;

const int GRID_SIZE = 20;

int main() {
    bool escapePressed = false;
    const int WINDOW_WIDTH = GRID_SIZE * 30;
    const int WINDOW_HEIGHT = GRID_SIZE * 50;
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Chicken Boy!");
    window.setFramerateLimit(60);

    // setting up player
    Player player;
    player.setPlayer();

    Vector2f velocity;
    velocity.y = 0.f;
    velocity.x = 0.f;
    Vector2f speed;
    speed.y = 0.f;
    speed.x = 0.f;
    FloatRect nextPos;

    const float GRAVITY = 0.9f; // Define gravity constant
    const float JUMP_VELOCITY = -15.f; // Define jump velocity

    // setting up map
    Walls wall;
    wall.setWalls();

    Spikes spike;
    spike.setSpikes();

    Finish finish;
    finish.setFinish();
    finish.setFinish2();
    
    // setting up sounds
    SoundBuffer bufferEnd;
    if (!bufferEnd.loadFromFile("sounds/goodEnding.wav"))
        return -1;
    Sound soundEnd;
    soundEnd.setBuffer(bufferEnd);
    soundEnd.setLoop(true);
    soundEnd.setVolume(60.f);

    SoundBuffer bufferDeath;
    if (!bufferDeath.loadFromFile("sounds/deathSound.wav"))
        return -1;
    Sound soundDeath;
    soundDeath.setBuffer(bufferDeath);
    soundDeath.setPlayingOffset(sf::milliseconds(700));
    soundDeath.setVolume(60.f);

    // setting up font
    Font font;
    if (!font.loadFromFile("fonts/G_ari_bd.TTF"))
        return -1;
    Text text;
    text.setFont(font);
    text.setCharacterSize(32);
    text.setColor(sf::Color::White);

    // start the game
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                escapePressed = true;
                window.close();
            }
            // close if escape is pressed
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                escapePressed = true;
                playSound(soundDeath);
            }
        }
        if(player.shape.getGlobalBounds().intersects(finish.shape.getGlobalBounds())) {
            window.close();
        }

        // movements -----------------------
        // jump 
        if (Keyboard::isKeyPressed(Keyboard::Up) && !player.isJumping) {
            // Jump if not already jumping
            player.isJumping = true;
            velocity.y = JUMP_VELOCITY; // Set vertical velocity to jump velocity
            // jump to the right when the wall is on the left
            if (Keyboard::isKeyPressed(Keyboard::Left) && player.onWall) {
                speed.x += 4.6f;
                velocity.x = speed.x;
            }
            // jump to the left when the wall is on the right
            if (Keyboard::isKeyPressed(Keyboard::Right) && player.onWall) {
                speed.x -= 4.6f;
                velocity.x = speed.x;
            }
        }
        // left movement
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            // don't go higher the maximum speed if he has reached it
            if (-player.maxSpeed >= speed.x) {
                velocity.x = -player.maxSpeed;
            }
            // apply inertia if he was going to the right before
            else if (speed.x > 0) {
                speed.x -= player.inertia;
                velocity.x = speed.x;
            }
            // slowly increasing the speed
            else {
                speed.x -= player.acceleration;
                velocity.x = speed.x;
            }
        }
        // right movement
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            // don't go higher the maximum speed if he has reached it
            if (player.maxSpeed <= speed.x) {
                velocity.x = player.maxSpeed;
            }
            // apply inertia if he was going to the left before
            else if (speed.x < 0) {
                speed.x += player.inertia;
                velocity.x = speed.x;
            }
            // slowly increasing the speed
            else {
                speed.x += player.acceleration;
                velocity.x = speed.x;
            }
        }
        // start stopping the player the left and right button are not pressed
        if (!Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right)) {
            // apply inertia before completely stop if he was moving to the left
            if (speed.x < 0) {
                speed.x += player.inertia;
                // completely stops
                if (speed.x >= 0) {
                    velocity.x = 0.f;
                }
                // continue applying inertia
                else {
                    velocity.x = speed.x;
                }
            }
            // apply inertia before completely stop if he was moving to the left
            if (speed.x > 0) {
                speed.x -= player.inertia;
                // completely stops
                if (speed.x <= 0) {
                    velocity.x = 0.f;
                }
                // continue applying inertia
                else {
                    velocity.x = speed.x;
                }
            }
        }

        // wall collisions -------------
        for (auto &wall : wall.walls) {
            // sets the player and wall bounds
            FloatRect playerBounds = player.shape.getGlobalBounds();
            FloatRect wallBounds = wall.getGlobalBounds();

            // position the bounds on the next position where the player is moving
            nextPos = playerBounds;
            nextPos.top += velocity.y;
            nextPos.left += velocity.x;

            // verifies collisions
            if (wallBounds.intersects(nextPos)) {
                // top : prevent the player from clipping into the roof, prevent from wall jumping or doing multiple jumps
                if (playerBounds.top > wallBounds.top
                && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left) {
                    velocity.y = 0.f;
                    player.shape.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
                    player.onWall = false;
                }
                // bottom : prevent the player from clipping into the floor, the player can jump again
                else if (playerBounds.top < wallBounds.top
                && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left) {
                    velocity.y = 0.f;
                    player.shape.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
                    player.isJumping = false;
                    player.onWall = false;
                }
                // left : prevent the player from clipping into the wall, the player can wall jump, reset the speed.X
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
                // right : prevent the player from clipping into the wall, the player can wall jump, reset the speed.X
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
                // prevent from doing multiple jumps (still not working)
                else {
                    player.isJumping = true;
                    player.onWall = false;
                }
            }
        }

        // Apply gravity
        velocity.y += GRAVITY;
        // move the player
        player.shape.move(velocity);

        // spikes collisions ---------------
        for (auto &spike : spike.spikes) {
            // sets the player and spikes bounds
            FloatRect playerBounds = player.shape.getGlobalBounds();
            FloatRect spikesBounds = spike.getGlobalBounds();

            if (spikesBounds.intersects(playerBounds)) {
                player.shape.setPosition(player.spawnPoint);
                soundDeath.setPlayingOffset(sf::milliseconds(750));
                soundDeath.play();
            }
        }

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

        // display everything -------------
        // clear before redrawing
        window.clear();
        // map
        for (auto &i : wall.walls) {
            window.draw(i);
        }
        for (auto &i : spike.spikes) {
            window.draw(i);
        }
        window.draw(finish.shape);
        window.draw(finish.shape2);
        // player
        player.draw(window);

        window.display();
    }

    // prepare the ending window
    RenderWindow window2(VideoMode(1065, 160), "Well done !");

    // playing sound
    soundEnd.play();

    // start ending window
    while (window2.isOpen()) {
        Event event;
        while (window2.pollEvent(event)) {
            if (event.type == Event::Closed)
                window2.close();
            // close if escape is pressed
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window2.close();
            // close if escape was pressed on the first window
            if (escapePressed)
                window2.close();
        }

        text.setString("\t\t\t\t\t\tWell done !! You have finished the level !! \nThis is all we got for now, but wait until the addition of more content ;) \n\n\t\tIf you want to play again, press escape and restart the game :)");

        window2.clear();
        window2.draw(text);
        window2.display();
    }

    return 0;
}