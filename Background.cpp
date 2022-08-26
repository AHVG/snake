#include "Background.h"
#include "Window.h"

sf::RenderWindow *Block::window = WindowInstance;
const sf::Vector2f Block::size = sf::Vector2f(21.0,21.0);

Block::Block(){
    position = sf::Vector2i(0,0);
    color = sf::Color::Red;
}

Block::Block(const sf::Color &col, const sf::Vector2i &pos) : color(col), position(pos){}

void Block::setColor(const sf::Color &newColor){
    color = newColor;
}

sf::Color Block::getColor() const{
    return color;
}

void Block::setPosition(const sf::Vector2i newPosition){
    position = newPosition;
}

sf::Vector2i Block::getPosition() const{
    return position;
}

sf::Vector2f Block::getSize() const{
    return size;
}

void Block::update(){
    position.y += 1;
}

void Block::render(){
    sf::RectangleShape shape;
    shape.setFillColor(color);
    shape.setSize(getSize());
    shape.setPosition(getSize().x * position.x, getSize().y * position.y);
    window->draw(shape);
}

const Block &Block::operator=(const Block &other){
    color = other.getColor();
    position = other.getPosition();
    return *this;
}



const sf::Vector2i Background::size = sf::Vector2i(20,20);

void Background::generateBlock(){
    sf::Vector2i position = sf::Vector2i(std::rand()%size.x, 0);
    sf::Color color;

    int chosen = std::rand()%4;
    if(chosen == 0)
        color = sf::Color(255,0,0);
    else if(chosen == 1)
        color = sf::Color(0,255,0);
    else if(chosen == 2)
        color = sf::Color(255,255,0);
    else
        color = sf::Color(0,0,255);

    blocks.push_back(new Block(color, position));
}

void Background::update(){

    if(clockUpdate.getElapsedTime().asMilliseconds() > updateSpeed){
        for(auto &block : blocks)
            block->update();
        clockUpdate.restart();
    }

    if(clockGeneration.getElapsedTime().asMilliseconds() > generationSpeed){
        generateBlock();
        clockGeneration.restart();
    }

    for(auto &block : blocks)
        if(block->getPosition().y > size.y)
            blocks.remove(block);
}

void Background::render(){
    for(auto &block : blocks)
        block->render();
}
