#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>

class Wall {
private:
    sf::RectangleShape shape;

public:
    Wall(sf::Vector2f position, sf::Vector2f size) {
        shape.setPosition(position);
        shape.setSize(size);
        shape.setFillColor(sf::Color::White);
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(shape);
    }

    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    }
};

#endif
