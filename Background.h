#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <list>

class Block {

    private:

    static const sf::Vector2f size;
    static sf::RenderWindow *window;
    sf::Color color;
    sf::Vector2i position;

    public:

    Block();
    Block(const sf::Color &col, const sf::Vector2i &pos);

    void setColor(const sf::Color &newColor);
    sf::Color getColor() const;

    void setPosition(const sf::Vector2i newPosition);
    sf::Vector2i getPosition() const;

    sf::Vector2f getSize() const;

    void update();
    void render();

    const Block &operator=(const Block &other);

};

class Background {

    private:

    static const sf::Vector2i size;

    std::list<Block *> blocks;

    sf::Clock clockUpdate;
    sf::Clock clockGeneration;
    const int updateSpeed = 40;
    const int generationSpeed = 40;

    void generateBlock();

    public:

    void update();
    void render();

};

#endif // BACKGROUND_H_INCLUDED
