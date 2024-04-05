class Finish {
public:
    const int GRID_SIZE = 20;
    
    sf::RectangleShape shape;
    sf::Texture finishTexture;

    void setFinish() {
        finishTexture.loadFromFile("img/finish.png");
        shape.setTexture(&finishTexture);
        shape.setPosition(sf::Vector2f(GRID_SIZE * 15, GRID_SIZE * 44)); shape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    }

};