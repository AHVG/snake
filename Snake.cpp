#include "Snake.h"
#include "Window.h"

sf::RenderWindow *BodyPart::window = WindowInstance;
const sf::Vector2f BodyPart::size = FieldInstance->getTileSize();

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
    shape.setPosition(sf::Vector2f(position) * 20.f + sf::Vector2f(10.0,10.0));
    shape.setSize(size);
    window->draw(shape);
}

const BodyPart &BodyPart::operator=(const BodyPart &other){
    position = other.getPosition();
    color = other.getColor();
    return *this;
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
    sf::Vector2i headPos = head->getPosition();

    if(headPos.x < 0){
        head->setPosition(sf::Vector2i(FieldInstance->getSize().x - 1, headPos.y));
    }
    if(headPos.x > FieldInstance->getSize().x - 1){
        head->setPosition(sf::Vector2i(0, head->getPosition().y));
    }
    if(headPos.y < 0){
        head->setPosition(sf::Vector2i(headPos.x, FieldInstance->getSize().y - 1));
    }
    if(headPos.y > FieldInstance->getSize().y - 1){
        head->setPosition(sf::Vector2i(headPos.x, 0));
    }
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
