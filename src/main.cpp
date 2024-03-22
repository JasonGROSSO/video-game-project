#include <iostream>
#include "player.hpp"

int start()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Super Chicken Boy!");
    window.setFramerateLimit(60);
    player firstPlayer;

    while (window.isOpen())
    {

        // go to the left if Q is pressed
        if (Keyboard::isKeyPressed(Keyboard::Q))
        {
            firstPlayer.getPosition();
            firstPlayer.goLeft();
            firstPlayer.move(direction);
        }
        // go to the right if D is pressed
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            firstPlayer.getPosition();
            firstPlayer.goRight();
            firstPlayer.move(direction);
        }
        // go up if Z is pressed
        if (Keyboard::isKeyPressed(Keyboard::Z))
        {
            firstPlayer.getPosition();
            firstPlayer.goUp();
            firstPlayer.move(direction);
        }
        // go down if S is pressed
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            firstPlayer.getPosition();
            firstPlayer.goDown();
            firstPlayer.move(direction);
        }

        // close the game if the esc key is pressed
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(firstPlayer);
        window.display();
    }
    return 0;    
}