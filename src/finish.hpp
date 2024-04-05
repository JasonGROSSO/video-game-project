class Finish {
public:
    const int GRID_SIZE = 20;
    
    sf::RectangleShape shape;
    sf::Texture finishTexture;

    void setFinish() {
        finishTexture.loadFromFile("img/Hormonica.png");
        shape.setTexture(&finishTexture);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 15, GRID_SIZE * 44)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    }

    sf::RectangleShape shape2;
    sf::Texture finishTexture2;

    void setFinish2() {
        finishTexture2.loadFromFile("img/Cluckenstein.png");
        shape2.setTexture(&finishTexture2);
        shape2.setPosition(sf::Vector2f(GRID_SIZE * 16, GRID_SIZE * 44)); shape2.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    }
};