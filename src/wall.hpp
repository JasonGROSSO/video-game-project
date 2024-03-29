class Wall {
private:
    int x, y; // Position of the wall
    int width, height; // Dimensions of the wall

public:
    // Constructor
    Wall(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

    // Getters
    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    // Setters
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setWidth(int width) { this->width = width; }
    void setHeight(int height) { this->height = height; }
};