#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

class BodyPart {

    private:

    static sf::RenderWindow *window;
    const static int size = 10;

    sf::Vector2i position;
    sf::Color color;

    public:

    BodyPart();
    BodyPart(sf::Vector2i pos, const sf::Color &col);

    void setPosition(const sf::Vector2i &newPosition);
    sf::Vector2i getPosition() const;

    void setColor(const sf::Color &newColor);
    sf::Color getColor() const;

    void render();

    BodyPart &operator=(const BodyPart &other);

};


class Snake {

    private:

    const int velocity = 300;

    sf::Vector2i direction;
    std::vector<BodyPart *> body;
    sf::Clock clock;

    public:

    Snake();
    ~Snake();

    void setDirection(const sf::Vector2i &newDirection);
    sf::Vector2i getDirection() const;

    void grow();
    int getSize() const;

    void moveForward();

    void handleInput();
    void update();
    void render();

};

#endif // SNAKE_H_INCLUDED
