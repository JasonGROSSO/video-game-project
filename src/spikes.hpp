class Spikes {
public:
    const int GRID_SIZE = 20;

    std::vector<sf::ConvexShape> spikes;
    sf::ConvexShape shape;

    void setSpikes() {
        shape.setPointCount(5);
        shape.setFillColor(sf::Color(0xafafafff));

        // spikes to the right
        for (int i = 0; i < 19; i++) {
            shape.setPoint(0, sf::Vector2f(GRID_SIZE * 4, (GRID_SIZE * (i + 3)) + 1)); shape.setPoint(1, sf::Vector2f((GRID_SIZE * 5)- 5, (GRID_SIZE * (i + 3)) + GRID_SIZE / 4)); shape.setPoint(2, sf::Vector2f(GRID_SIZE * 4, (GRID_SIZE * (i + 3)) + GRID_SIZE / 2)); shape.setPoint(3, sf::Vector2f((GRID_SIZE * 5) - 5, (GRID_SIZE * (i + 3)) + ((GRID_SIZE / 4) * 3))); shape.setPoint(4, sf::Vector2f(GRID_SIZE * 4, (GRID_SIZE * (i + 4)) - 1)); spikes.push_back(shape);
        }
        for (int i = 0; i < 3; i++) {
            shape.setPoint(0, sf::Vector2f(GRID_SIZE * 4, (GRID_SIZE * (i + 36)) + 1)); shape.setPoint(1, sf::Vector2f((GRID_SIZE * 5)- 5, (GRID_SIZE * (i + 36)) + GRID_SIZE / 4)); shape.setPoint(2, sf::Vector2f(GRID_SIZE * 4, (GRID_SIZE * (i + 36)) + GRID_SIZE / 2)); shape.setPoint(3, sf::Vector2f((GRID_SIZE * 5) - 5, (GRID_SIZE * (i + 36)) + ((GRID_SIZE / 4) * 3))); shape.setPoint(4, sf::Vector2f(GRID_SIZE * 4, (GRID_SIZE * (i + 37)) - 1)); spikes.push_back(shape);
        }
        for (int i = 0; i < 4; i++) {
            shape.setPoint(0, sf::Vector2f(GRID_SIZE * 11, (GRID_SIZE * (i + 36)) + 1)); shape.setPoint(1, sf::Vector2f((GRID_SIZE * 12)- 5, (GRID_SIZE * (i + 36)) + GRID_SIZE / 4)); shape.setPoint(2, sf::Vector2f(GRID_SIZE * 11, (GRID_SIZE * (i + 36)) + GRID_SIZE / 2)); shape.setPoint(3, sf::Vector2f((GRID_SIZE * 12) - 5, (GRID_SIZE * (i + 36)) + ((GRID_SIZE / 4) * 3))); shape.setPoint(4, sf::Vector2f(GRID_SIZE * 11, (GRID_SIZE * (i + 37)) - 1)); spikes.push_back(shape);
        }
        for (int i = 0; i < 4; i++) {
            shape.setPoint(0, sf::Vector2f(GRID_SIZE * 17, (GRID_SIZE * (i + 31)) + 1)); shape.setPoint(1, sf::Vector2f((GRID_SIZE * 18)- 5, (GRID_SIZE * (i + 31)) + GRID_SIZE / 4)); shape.setPoint(2, sf::Vector2f(GRID_SIZE * 17, (GRID_SIZE * (i + 31)) + GRID_SIZE / 2)); shape.setPoint(3, sf::Vector2f((GRID_SIZE * 18) - 5, (GRID_SIZE * (i + 31)) + ((GRID_SIZE / 4) * 3))); shape.setPoint(4, sf::Vector2f(GRID_SIZE * 17, (GRID_SIZE * (i + 32)) - 1)); spikes.push_back(shape);
        }
        for (int i = 0; i < 7; i++) {
            shape.setPoint(0, sf::Vector2f(GRID_SIZE * 22, (GRID_SIZE * (i + 40)) + 1)); shape.setPoint(1, sf::Vector2f((GRID_SIZE * 23)- 5, (GRID_SIZE * (i + 40)) + GRID_SIZE / 4)); shape.setPoint(2, sf::Vector2f(GRID_SIZE * 22, (GRID_SIZE * (i + 40)) + GRID_SIZE / 2)); shape.setPoint(3, sf::Vector2f((GRID_SIZE * 23) - 5, (GRID_SIZE * (i + 40)) + ((GRID_SIZE / 4) * 3))); shape.setPoint(4, sf::Vector2f(GRID_SIZE * 22, (GRID_SIZE * (i + 41)) - 1)); spikes.push_back(shape);
        }
        for (int i = 0; i < 2; i++) {
            shape.setPoint(0, sf::Vector2f(GRID_SIZE * 11, (GRID_SIZE * (i + 19)) + 1)); shape.setPoint(1, sf::Vector2f((GRID_SIZE * 12)- 5, (GRID_SIZE * (i + 19)) + GRID_SIZE / 4)); shape.setPoint(2, sf::Vector2f(GRID_SIZE * 11, (GRID_SIZE * (i + 19)) + GRID_SIZE / 2)); shape.setPoint(3, sf::Vector2f((GRID_SIZE * 12) - 5, (GRID_SIZE * (i + 19)) + ((GRID_SIZE / 4) * 3))); shape.setPoint(4, sf::Vector2f(GRID_SIZE * 11, (GRID_SIZE * (i + 20)) - 1)); spikes.push_back(shape);
        }

        // spikes to the top
        for (int i = 0; i < 23; i++) {
            shape.setPoint(0, sf::Vector2f((GRID_SIZE * (i + 6)) + 1, (GRID_SIZE * 30))); shape.setPoint(1, sf::Vector2f((GRID_SIZE * (i + 6)) + GRID_SIZE / 4, (GRID_SIZE * 30) - 15)); shape.setPoint(2, sf::Vector2f((GRID_SIZE * (i + 6)) + GRID_SIZE / 2, (GRID_SIZE * 30))); shape.setPoint(3, sf::Vector2f((GRID_SIZE * (i + 6)) + ((GRID_SIZE / 4) * 3), (GRID_SIZE * 30) - 15)); shape.setPoint(4, sf::Vector2f((GRID_SIZE * (i + 7)) - 1, (GRID_SIZE * 30))); spikes.push_back(shape);
        }
        for (int i = 0; i < 2; i++) {
            shape.setPoint(0, sf::Vector2f((GRID_SIZE * (i + 13)) + 1, (GRID_SIZE * 8))); shape.setPoint(1, sf::Vector2f((GRID_SIZE * (i + 13)) + GRID_SIZE / 4, (GRID_SIZE * 8) - 15)); shape.setPoint(2, sf::Vector2f((GRID_SIZE * (i + 13)) + GRID_SIZE / 2, (GRID_SIZE * 8))); shape.setPoint(3, sf::Vector2f((GRID_SIZE * (i + 13)) + ((GRID_SIZE / 4) * 3), (GRID_SIZE * 8) - 15)); shape.setPoint(4, sf::Vector2f((GRID_SIZE * (i + 14)) - 1, (GRID_SIZE * 8))); spikes.push_back(shape);
        }
        for (int i = 0; i < 2; i++) {
            shape.setPoint(0, sf::Vector2f((GRID_SIZE * (i + 18)) + 1, (GRID_SIZE * 13))); shape.setPoint(1, sf::Vector2f((GRID_SIZE * (i + 18)) + GRID_SIZE / 4, (GRID_SIZE * 13) - 15)); shape.setPoint(2, sf::Vector2f((GRID_SIZE * (i + 18)) + GRID_SIZE / 2, (GRID_SIZE * 13))); shape.setPoint(3, sf::Vector2f((GRID_SIZE * (i + 18)) + ((GRID_SIZE / 4) * 3), (GRID_SIZE * 13) - 15)); shape.setPoint(4, sf::Vector2f((GRID_SIZE * (i + 19)) - 1, (GRID_SIZE * 13))); spikes.push_back(shape);
        }
        for (int i = 0; i < 6; i++) {
            shape.setPoint(0, sf::Vector2f((GRID_SIZE * (i + 4)) + 1, (GRID_SIZE * 40))); shape.setPoint(1, sf::Vector2f((GRID_SIZE * (i + 4)) + GRID_SIZE / 4, (GRID_SIZE * 40) - 15)); shape.setPoint(2, sf::Vector2f((GRID_SIZE * (i + 4)) + GRID_SIZE / 2, (GRID_SIZE * 40))); shape.setPoint(3, sf::Vector2f((GRID_SIZE * (i + 4)) + ((GRID_SIZE / 4) * 3), (GRID_SIZE * 40) - 15)); shape.setPoint(4, sf::Vector2f((GRID_SIZE * (i + 5)) - 1, (GRID_SIZE * 40))); spikes.push_back(shape);
        }
        for (int i = 0; i < 4; i++) {
            shape.setPoint(0, sf::Vector2f((GRID_SIZE * (i + 25)) + 1, (GRID_SIZE * 49))); shape.setPoint(1, sf::Vector2f((GRID_SIZE * (i + 25)) + GRID_SIZE / 4, (GRID_SIZE * 49) - 15)); shape.setPoint(2, sf::Vector2f((GRID_SIZE * (i + 25)) + GRID_SIZE / 2, (GRID_SIZE * 49))); shape.setPoint(3, sf::Vector2f((GRID_SIZE * (i + 25)) + ((GRID_SIZE / 4) * 3), (GRID_SIZE * 49) - 15)); shape.setPoint(4, sf::Vector2f((GRID_SIZE * (i + 26)) - 1, (GRID_SIZE * 49))); spikes.push_back(shape);
        }
        for (int i = 0; i < 1; i++) {
            shape.setPoint(0, sf::Vector2f((GRID_SIZE * (i + 16)) + 1, (GRID_SIZE * 40))); shape.setPoint(1, sf::Vector2f((GRID_SIZE * (i + 16)) + GRID_SIZE / 4, (GRID_SIZE * 40) - 15)); shape.setPoint(2, sf::Vector2f((GRID_SIZE * (i + 16)) + GRID_SIZE / 2, (GRID_SIZE * 40))); shape.setPoint(3, sf::Vector2f((GRID_SIZE * (i + 16)) + ((GRID_SIZE / 4) * 3), (GRID_SIZE * 40) - 15)); shape.setPoint(4, sf::Vector2f((GRID_SIZE * (i + 17)) - 1, (GRID_SIZE * 40))); spikes.push_back(shape);
        }

        // spikes to the left
        for (int i = 0; i < 28; i++) {
            shape.setPoint(0, sf::Vector2f(GRID_SIZE * 29, (GRID_SIZE * (i + 1)) + 1)); shape.setPoint(1, sf::Vector2f((GRID_SIZE * 28) + 5, (GRID_SIZE * (i + 1)) + GRID_SIZE / 4)); shape.setPoint(2, sf::Vector2f(GRID_SIZE * 29, (GRID_SIZE * (i + 1)) + GRID_SIZE / 2)); shape.setPoint(3, sf::Vector2f((GRID_SIZE * 28) + 5, (GRID_SIZE * (i + 1)) + ((GRID_SIZE / 4) * 3))); shape.setPoint(4, sf::Vector2f(GRID_SIZE * 29, (GRID_SIZE * (i + 2)) - 1)); spikes.push_back(shape);
        }
        for (int i = 0; i < 17; i++) {
            shape.setPoint(0, sf::Vector2f(GRID_SIZE * 29, (GRID_SIZE * (i + 31)) + 1)); shape.setPoint(1, sf::Vector2f((GRID_SIZE * 28) + 5, (GRID_SIZE * (i + 31)) + GRID_SIZE / 4)); shape.setPoint(2, sf::Vector2f(GRID_SIZE * 29, (GRID_SIZE * (i + 31)) + GRID_SIZE / 2)); shape.setPoint(3, sf::Vector2f((GRID_SIZE * 28) + 5, (GRID_SIZE * (i + 31)) + ((GRID_SIZE / 4) * 3))); shape.setPoint(4, sf::Vector2f(GRID_SIZE * 29, (GRID_SIZE * (i + 32)) - 1)); spikes.push_back(shape);
        }
        for (int i = 0; i < 3; i++) {
            shape.setPoint(0, sf::Vector2f(GRID_SIZE * 10, (GRID_SIZE * (i + 36)) + 1)); shape.setPoint(1, sf::Vector2f((GRID_SIZE * 9) + 5, (GRID_SIZE * (i + 36)) + GRID_SIZE / 4)); shape.setPoint(2, sf::Vector2f(GRID_SIZE * 10, (GRID_SIZE * (i + 36)) + GRID_SIZE / 2)); shape.setPoint(3, sf::Vector2f((GRID_SIZE * 9) + 5, (GRID_SIZE * (i + 36)) + ((GRID_SIZE / 4) * 3))); shape.setPoint(4, sf::Vector2f(GRID_SIZE * 10, (GRID_SIZE * (i + 37)) - 1)); spikes.push_back(shape);
        }
        for (int i = 0; i < 4; i++) {
            shape.setPoint(0, sf::Vector2f(GRID_SIZE * 16, (GRID_SIZE * (i + 31)) + 1)); shape.setPoint(1, sf::Vector2f((GRID_SIZE * 15) + 5, (GRID_SIZE * (i + 31)) + GRID_SIZE / 4)); shape.setPoint(2, sf::Vector2f(GRID_SIZE * 16, (GRID_SIZE * (i + 31)) + GRID_SIZE / 2)); shape.setPoint(3, sf::Vector2f((GRID_SIZE * 15) + 5, (GRID_SIZE * (i + 31)) + ((GRID_SIZE / 4) * 3))); shape.setPoint(4, sf::Vector2f(GRID_SIZE * 16, (GRID_SIZE * (i + 32)) - 1)); spikes.push_back(shape);
        }
        for (int i = 0; i < 2; i++) {
            shape.setPoint(0, sf::Vector2f(GRID_SIZE * 10, (GRID_SIZE * (i + 19)) + 1)); shape.setPoint(1, sf::Vector2f((GRID_SIZE * 9) + 5, (GRID_SIZE * (i + 19)) + GRID_SIZE / 4)); shape.setPoint(2, sf::Vector2f(GRID_SIZE * 10, (GRID_SIZE * (i + 19)) + GRID_SIZE / 2)); shape.setPoint(3, sf::Vector2f((GRID_SIZE * 9) + 5, (GRID_SIZE * (i + 19)) + ((GRID_SIZE / 4) * 3))); shape.setPoint(4, sf::Vector2f(GRID_SIZE * 10, (GRID_SIZE * (i + 20)) - 1)); spikes.push_back(shape);
        }
        for (int i = 0; i < 2; i++) {
            shape.setPoint(0, sf::Vector2f(GRID_SIZE * 17, (GRID_SIZE * (i + 17)) + 1)); shape.setPoint(1, sf::Vector2f((GRID_SIZE * 16) + 5, (GRID_SIZE * (i + 17)) + GRID_SIZE / 4)); shape.setPoint(2, sf::Vector2f(GRID_SIZE * 17, (GRID_SIZE * (i + 17)) + GRID_SIZE / 2)); shape.setPoint(3, sf::Vector2f((GRID_SIZE * 16) + 5, (GRID_SIZE * (i + 17)) + ((GRID_SIZE / 4) * 3))); shape.setPoint(4, sf::Vector2f(GRID_SIZE * 17, (GRID_SIZE * (i + 18)) - 1)); spikes.push_back(shape);
        }
    }
};