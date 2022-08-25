#include <iostream>
#include "Snake.h"
#include "Window.h"

sf::RenderWindow *BodyPart::window = WindowInstance;
const sf::Vector2f BodyPart::size = FieldInstance->getTileSize();

BodyPart::BodyPart(){
    position = sf::Vector2i(0,0);
    color = sf::Color::Green;
}

BodyPart::BodyPart(sf::Vector2i pos, const sf::Color &col) : position(pos), color(col){}

sf::Vector2f BodyPart::getSize() const{
    return size;
}

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
    shape.setPosition(sf::Vector2f(position.x * getSize().x, position.y * getSize().y) + FieldInstance->getMargin());
    shape.setSize(size);
    window->draw(shape);
}

const BodyPart &BodyPart::operator=(const BodyPart &other){
    position = other.getPosition();
    color = other.getColor();
    return *this;
}




Snake::Snake(){
    currentDirection = sf::Vector2i(0,1);
    nextDirection = currentDirection;
    body.push_back(new BodyPart(sf::Vector2i(0,0), sf::Color::Green));
    canGrow = false;
}

Snake::~Snake(){
    for(auto &bodyPart : body){
        delete bodyPart;
        bodyPart = nullptr;
    }
    body.clear();
}

void Snake::setCurrentDirection(const sf::Vector2i &newDirection){
    currentDirection = newDirection;
}

sf::Vector2i Snake::getCurrentDirection() const{
    return currentDirection;
}

void Snake::setNextDirection(const sf::Vector2i &newDirection){
    nextDirection = newDirection;
}

sf::Vector2i Snake::getNextDirection() const{
    return nextDirection;
}

sf::Vector2i Snake::getHeadPosition() const{
    return body.at(0)->getPosition();
}

std::vector<sf::Vector2i> Snake::getPositions() const{
    std::vector<sf::Vector2i> positions;
    for(auto bodyPart : body)
        positions.push_back(bodyPart->getPosition());
    return positions;
}

bool Snake::eat(const sf::Vector2i &foodPosition) {
    if(getHeadPosition() == foodPosition){
        canGrow = true;
        return true;
    }
    return false;
}

void Snake::grow(){
    BodyPart *finalPart = body.at(body.size() - 1);
    body.push_back(new BodyPart(finalPart->getPosition(), sf::Color::Green));
    canGrow = false;
}

int Snake::getSize() const{
    return body.size();
}

void Snake::moveForward(){
    for(int i = body.size() - 1; i > 0; i--)
        body.at(i)->setPosition(body.at(i - 1)->getPosition());

    BodyPart *head = body.at(0);
    head->setPosition(head->getPosition() + getCurrentDirection());
    sf::Vector2i headPos = head->getPosition();

    if(headPos.x < 0)
        head->setPosition(sf::Vector2i(FieldInstance->getSize().x - 1, headPos.y));
    if(headPos.x > FieldInstance->getSize().x - 1)
        head->setPosition(sf::Vector2i(0, head->getPosition().y));
    if(headPos.y < 0)
        head->setPosition(sf::Vector2i(headPos.x, FieldInstance->getSize().y - 1));
    if(headPos.y > FieldInstance->getSize().y - 1)
        head->setPosition(sf::Vector2i(headPos.x, 0));
}

void Snake::handleInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && getCurrentDirection().y != 1)
        setNextDirection(sf::Vector2i(0,-1));
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && getCurrentDirection().y != -1)
        setNextDirection(sf::Vector2i(0,1));
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && getCurrentDirection().x != 1)
        setNextDirection(sf::Vector2i(-1,0));
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && getCurrentDirection().x != -1)
        setNextDirection(sf::Vector2i(1,0));
}

void Snake::update(){
    handleInput();
    if(clock.getElapsedTime().asMilliseconds() >= velocity){
        if(canGrow)
            grow();
        setCurrentDirection(nextDirection);
        moveForward();
        clock.restart();
    }
}

void Snake::render(){
    for(auto &bodyPart : body)
        bodyPart->render();
}
