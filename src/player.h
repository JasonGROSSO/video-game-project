#include <SFML/Graphics.hpp>

using namespace sf;

class player
{
public:

    aPlayer->Vector2f position;
    aPlayer->Vector2f direction;
    aPlayer->CircleShape shape;

    void goLeft()
    {
        position = aPlayer->getPosition();

        direction.x = -5;
        direction.y = 0;

        aPlayer->move(direction);
    }

    void goRight()
    {
        position = aPlayer->getPosition();

        direction.x = 5;
        direction.y = 0;

        aPlayer->move(direction);
    }

    void goUp()
    {
        position = aPlayer->getPosition();

        direction.x = 0;
        direction.y = 5;

        aPlayer->move(direction);
    }

    void goDown()
    {
        position = aPLayer->getPosition();

        direction.x = 0;
        direction.y = -5;

        aPLayer->move(direction);
    }
    
};
