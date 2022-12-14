#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include "Field.h"

class BodyPart {

    private:

    static sf::RenderWindow *window;
    static const sf::Vector2f size;

    sf::Vector2i position;
    sf::Color color;

    public:

    BodyPart();
    BodyPart(sf::Vector2i pos, const sf::Color &col);

    sf::Vector2f getSize() const;

    void setPosition(const sf::Vector2i &newPosition);
    sf::Vector2i getPosition() const;

    void setColor(const sf::Color &newColor);
    sf::Color getColor() const;

    void render();

    const BodyPart &operator=(const BodyPart &other);

};


class Snake {

    private:

    const int velocity = 200;

    sf::Vector2i currentDirection;
    sf::Vector2i nextDirection;
    std::vector<BodyPart *> body;
    sf::Clock clock;

    bool canGrow;
    bool alive;

    sf::Color currentColor;

    public:

    Snake();
    ~Snake();

    void revive();
    void die();
    bool isAlive() const;

    void setCurrentDirection(const sf::Vector2i &newDirection);
    sf::Vector2i getCurrentDirection() const;

    void setNextDirection(const sf::Vector2i &newDirection);
    sf::Vector2i getNextDirection() const;

    sf::Vector2i getHeadPosition() const;

    std::vector<sf::Vector2i> getPositions() const;

    int getSize() const;

    sf::Color getNextColor();

    void grow();
    bool eat(const sf::Vector2i &foodPosition);
    bool collidedWithYourself() const;
    void moveForward();

    void reset();

    void handleInput();
    void update();
    void render();

};

#endif // SNAKE_H_INCLUDED
