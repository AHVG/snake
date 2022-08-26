#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include <SFML/Graphics.hpp>

class Field {

    private:

    Field();

    static Field *instance;

    sf::RenderWindow *window;
    const sf::Vector2i size = sf::Vector2i(10, 10);
    const sf::Vector2f tileSize = sf::Vector2f(40.0, 40.0);
    const sf::Vector2f margin = sf::Vector2f(10.0,10.0);

    public:

    ~Field();

    sf::Vector2i getSize() const;
    sf::Vector2f getTileSize() const;
    sf::Vector2f getMargin() const;

    static Field *getInstance();

    void render();

};

#define FieldInstance Field::getInstance()

#endif // FIELD_H_INCLUDED
