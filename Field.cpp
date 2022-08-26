#include <iostream>
#include "Field.h"
#include "Window.h"

Field *Field::instance = nullptr;

Field::Field() : window(WindowInstance){}

Field::~Field(){
    delete instance;
}

sf::Vector2i Field::getSize() const{
    return size;
}

sf::Vector2f Field::getTileSize() const{
    return tileSize;
}

sf::Vector2f Field::getMargin() const{
    return margin;
}

Field *Field::getInstance(){
    if(instance == nullptr)
        instance = new Field;
    return instance;
}

void Field::render(){
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(getTileSize()));
    for(int line = 0; line < getSize().y; line++){
        for(int column = 0; column < getSize().x; column++){
            if((line + column) % 2)
                shape.setFillColor(sf::Color(50,50,50));
            else
                shape.setFillColor(sf::Color::Black);
            sf::Vector2f pos = sf::Vector2f(getTileSize().x * column + getMargin().x, getTileSize().y * line + getMargin().y);
            shape.setPosition(pos);
            window->draw(shape);
        }
    }
}
