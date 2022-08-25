#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

#include <SFML/Graphics.hpp>

class Food {

    private:

    static sf::RenderWindow *window;
    static const sf::Vector2f size;

    sf::Vector2i position;

    public:

    Food();
    Food(const sf::Vector2i &pos);

    sf::Vector2f getSize() const;

    void setPosition(const sf::Vector2i &newPosition);
    sf::Vector2i getPosition() const;

    void render();

    const Food &operator=(const Food &other);

};

#endif // FOOD_H_INCLUDED
