#include <SFML/Graphics.hpp>

class Wall {
private:
    sf::RectangleShape shape;

public:
    Wall(sf::Vector2f position, sf::Vector2f size) {
        shape.setPosition(position);
        shape.setSize(size);
        shape.setFillColor(sf::Color::White); // Change this to the color you want
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    }
};

