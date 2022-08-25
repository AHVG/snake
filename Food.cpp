#include "Food.h"
#include "Field.h"
#include "Window.h"

sf::RenderWindow *Food::window = WindowInstance;
const sf::Vector2f Food::size = FieldInstance->getTileSize();

Food::Food(){
    position = sf::Vector2i(0,0);
}

Food::Food(const sf::Vector2i &pos){
    position = pos;
}

sf::Vector2f Food::getSize() const{
    return size;
}

void Food::setPosition(const sf::Vector2i &newPosition){
    position = newPosition;
}

sf::Vector2i Food::getPosition() const{
    return position;
}


void Food::render(){
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Red);
    shape.setSize(getSize());
    shape.setPosition(sf::Vector2f(position.x * getSize().x, position.y * getSize().y) + FieldInstance->getMargin());
    window->draw(shape);
}

const Food &Food::operator=(const Food &other){
    position = other.getPosition();
    return *this;
}
