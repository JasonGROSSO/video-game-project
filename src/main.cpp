#include <iostream>
#include "player.h"

int start()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Super Chicken Boy!");
    window.setFramerateLimit(60);
    player firstPlayer;
    firstPlayer.shape = 50.f;

    while (window.isOpen())
    {

        // go to the left if Q is pressed
        if (Keyboard::isKeyPressed(Keyboard::Q))
        {
            firstPlayer.goLeft();
        }
        // go to the right if D is pressed
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            firstPlayer.goRight();
        }
        // go up if Z is pressed
        if (Keyboard::isKeyPressed(Keyboard::Z))
        {
            firstPlayer.goUp();
        }
        // go down if S is pressed
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            firstPlayer.goDown();
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