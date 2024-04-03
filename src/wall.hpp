class Wall {
public:
    sf::RectangleShape shape;

    Wall(sf::Vector2f position, sf::Vector2f size) {
        shape.setPosition(position);
        shape.setSize(size);
        shape.setFillColor(sf::Color::Red); // Change this to the color you want
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
};