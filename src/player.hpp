#include <SFML/Graphics.hpp>

using namespace sf;

class player
{
public:

    Vector2f direction;
    Vector2f position;

    void goLeft()
    {

        direction.x = -5;
        direction.y = 0;

    }

    void goRight()
    {

        direction.x = 5;
        direction.y = 0;

    }

    void goUp()
    {
        direction.x = 0;
        direction.y = 5;
    }

    void goDown()
    {
        direction.x = 0;
        direction.y = -5;
    }
    
};
