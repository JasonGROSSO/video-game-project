const int GRID_SIZE = 20;

class Walls {
public:
    std::vector<sf::RectangleShape> walls;
    sf::RectangleShape shape;

    void setWalls() {
        shape.setFillColor(sf::Color(0x6f6f6fff));

        // Main walls
        shape.setPosition(sf::Vector2f(0, GRID_SIZE * 49)); shape.setSize(sf::Vector2f(GRID_SIZE * 30, GRID_SIZE)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(0, GRID_SIZE * 45)); shape.setSize(sf::Vector2f(GRID_SIZE * 22, GRID_SIZE * 2)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 29, GRID_SIZE)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE * 48)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(0, 0)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE * 45)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(0, 0)); shape.setSize(sf::Vector2f(GRID_SIZE * 30, GRID_SIZE)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 3, GRID_SIZE * 2)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE * 41)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 3, GRID_SIZE * 40)); shape.setSize(sf::Vector2f(GRID_SIZE * 19, GRID_SIZE)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 19, GRID_SIZE * 41)); shape.setSize(sf::Vector2f(GRID_SIZE * 3, GRID_SIZE * 4)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 6, GRID_SIZE * 30)); shape.setSize(sf::Vector2f(GRID_SIZE * 24, GRID_SIZE)); walls.push_back(shape);

        // Other walls
    }
};

class Spikes {
public:
    std::vector<sf::ConvexShape> spikes;
    sf::ConvexShape shape;

    void setSpikes() {
        shape.setPointCount(5);
        shape.setFillColor(sf::Color(0xafafafff));

        //shape.setPoint(0, sf::Vector2f()); shape.setPoint(0, sf::Vector2f()); shape.setPoint(0, sf::Vector2f()); shape.setPoint(0, sf::Vector2f()); shape.setPoint(0, sf::Vector2f()); spikes.push_back(shape);
    }
    
};