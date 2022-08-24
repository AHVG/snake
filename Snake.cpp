#include "Snake.h"
#include "Window.h"

sf::RenderWindow *BodyPart::window = WindowInstance;

BodyPart::BodyPart(){
    position = sf::Vector2i(0,0);
    color = sf::Color::Green;
}

BodyPart::BodyPart(sf::Vector2i pos, const sf::Color &col) : position(pos), color(col){}

void BodyPart::setPosition(const sf::Vector2i &newPosition){
    position = newPosition;
}

sf::Vector2i BodyPart::getPosition() const{
    return position;
}

void BodyPart::setColor(const sf::Color &newColor){
    color = newColor;
}

sf::Color BodyPart::getColor() const{
    return color;
}

void BodyPart::render(){
    sf::RectangleShape shape;
    shape.setFillColor(color);
    shape.setPosition(sf::Vector2f(position) * 10.f);
    shape.setSize(sf::Vector2f(size, size));
    window->draw(shape);
}

BodyPart &BodyPart::operator=(const BodyPart &other){
    position = other.getPosition();
    color = other.getColor();
}



Snake::Snake(){
    direction = sf::Vector2i(0,1);
    body.push_back(new BodyPart(sf::Vector2i(0,0), sf::Color::Green));
}

Snake::~Snake(){
    for(auto &bodyPart : body){
        delete bodyPart;
        bodyPart = nullptr;
    }
    body.clear();
}

void Snake::setDirection(const sf::Vector2i &newDirection){
    direction = newDirection;
}

sf::Vector2i Snake::getDirection() const{
    return direction;
}

void Snake::grow(){
    BodyPart *finalPart = *(body.end());
    body.push_back(new BodyPart(finalPart->getPosition(), sf::Color::Green));
}

int Snake::getSize() const{
    return body.size();
}

void Snake::moveForward(){
    for(int i = body.size() - 1; i > 0; i--){
        body.at(i)->setPosition(body.at(i - 1)->getPosition());
    }
    BodyPart *head = body.at(0);
    head->setPosition(head->getPosition() + direction);
}

void Snake::handleInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && getDirection().y != 1){
        setDirection(sf::Vector2i(0,-1));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && getDirection().y != -1){
        setDirection(sf::Vector2i(0,1));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && getDirection().x != 1){
        setDirection(sf::Vector2i(-1,0));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && getDirection().x != -1){
        setDirection(sf::Vector2i(1,0));
    }
}

void Snake::update(){
    handleInput();
    if(clock.getElapsedTime().asMilliseconds() >= velocity){
        moveForward();
        clock.restart();
    }
}

void Snake::render(){
    for(auto &bodyPart : body){
        bodyPart->render();
    }
}
