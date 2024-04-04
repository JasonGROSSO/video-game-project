class Finish {
public:
    sf::RectangleShape shape;

    void setFinish() {
        shape.setFillColor(sf::Color::Magenta);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 15, GRID_SIZE * 44)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    }

};