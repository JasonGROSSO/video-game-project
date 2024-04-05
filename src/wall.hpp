class Walls {
public:
    const int GRID_SIZE = 20;

    std::vector<sf::RectangleShape> walls;
    sf::RectangleShape shape;
    sf::Texture wallTexture;

    void setWalls() {
        wallTexture.loadFromFile("img/wallTexture.jpg");
        wallTexture.setRepeated(true);
        shape.setTexture(&wallTexture);

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
        shape.setPosition(sf::Vector2f(GRID_SIZE * 23, GRID_SIZE * 46)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 27, GRID_SIZE * 41)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 16, GRID_SIZE * 31)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE * 4)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 10, GRID_SIZE * 36)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE * 4)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 8, GRID_SIZE * 27)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 14, GRID_SIZE * 25)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 15, GRID_SIZE * 28)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 23, GRID_SIZE * 26)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 25, GRID_SIZE * 21)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 17, GRID_SIZE * 17)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE * 2)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 10, GRID_SIZE * 19)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE * 2)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 11, GRID_SIZE * 15)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 15, GRID_SIZE * 11)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 13, GRID_SIZE * 8)); shape.setSize(sf::Vector2f(GRID_SIZE * 2, GRID_SIZE)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 15, GRID_SIZE * 11)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 24, GRID_SIZE * 12)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 18, GRID_SIZE * 13)); shape.setSize(sf::Vector2f(GRID_SIZE * 2, GRID_SIZE)); walls.push_back(shape);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 24, GRID_SIZE * 12)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 26, GRID_SIZE * 7)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 22, GRID_SIZE * 3)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 19, GRID_SIZE * 3)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 16, GRID_SIZE * 3)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 13, GRID_SIZE * 3)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 10, GRID_SIZE * 5)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
        shape.setPosition(sf::Vector2f(GRID_SIZE * 7, GRID_SIZE * 7)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE)); walls.push_back(shape); // simple cube
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