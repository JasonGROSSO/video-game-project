//class Wall {
//public:
//    sf::RectangleShape shape;
//
//    Wall(sf::Vector2f position, sf::Vector2f size) {
//        shape.setPosition(position);
//        shape.setSize(size);
//        shape.setFillColor(sf::Color{0x6f6f6fff}); // Change this to the color you want
//    }
//
//    void draw(sf::RenderWindow& window) {
//        window.draw(shape);
//    }
//};
const int GRID_SIZE = 20;

class Walls {
public:
    std::vector<sf::RectangleShape> walls;
    sf::RectangleShape shape;

    void setWalls() {
        shape.setFillColor(sf::Color{0x6f6f6fff});
        shape.setPosition(sf::Vector2f(0, GRID_SIZE * 49)); shape.setSize(sf::Vector2f(GRID_SIZE * 30, GRID_SIZE)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(0, GRID_SIZE * 45)); shape.setSize(sf::Vector2f(GRID_SIZE * 22, GRID_SIZE * 2)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 29, GRID_SIZE * 37)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE * 12)); walls.push_back(shape);
    }
};