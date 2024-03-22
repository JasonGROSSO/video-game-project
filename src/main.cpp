#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp" 

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Super Chicken Boy");
    sf::RectangleShape shape(sf::Vector2f(50.f, 50.f));
    shape.setFillColor(sf::Color::Red);

    // Define variables for gravity
    float gravity = 9.8; // m/s^2, you can adjust this value
    float velocity = 0;  // Initial velocity
    float dt = 0.1;      // Time step

    float speed = 0.2f; // horizontal mouvement speed of the object

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        handleMovement(shape, window, speed, gravity, velocity, dt);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
