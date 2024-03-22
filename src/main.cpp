#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp" 

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Super Chicken Boy");
    sf::RectangleShape shape(sf::Vector2f(50.f, 50.f));
    shape.setFillColor(sf::Color::Red);

    float speed = 0.2f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        handleMovement(shape, window, speed);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
