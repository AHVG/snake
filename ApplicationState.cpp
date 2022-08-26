#include "ApplicationState.h"
#include "Window.h"
#include "Field.h"

ApplicationState::ApplicationState(Application *app) : owner(app){}


InMenu *InMenu::instance = nullptr;

InMenu::InMenu(Application *app) : ApplicationState(app){
    font.loadFromFile("./fonts/ARCADECLASSIC.ttf");
    title.setFont(font);
    title.setString("Snake");
    title.setCharacterSize(80);
    title.setOrigin(title.getLocalBounds().width/2.0, title.getLocalBounds().height/2.0);
    title.setPosition(WindowInstance->getSize().x/2.0, title.getLocalBounds().height * 1.5);
    title.setFillColor(sf::Color::Yellow);

    subtitle.setFont(font);
    subtitle.setString("By   Augusto");
    subtitle.setCharacterSize(10);
    subtitle.setOrigin(subtitle.getLocalBounds().width/2.0, subtitle.getLocalBounds().height/2.0);
    subtitle.setPosition(WindowInstance->getSize().x/2.0, title.getLocalBounds().height * 3 + subtitle.getLocalBounds().height);
    subtitle.setFillColor(sf::Color::Yellow);

    play.setFont(font);
    play.setString("press   enter   to   play");
    play.setCharacterSize(25);
    play.setOrigin(play.getLocalBounds().width/2.0, play.getLocalBounds().height/2.0);
    play.setPosition(WindowInstance->getSize().x/2.0, WindowInstance->getSize().y * 2.0/3.0);
}

void InMenu::handleTrasition(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        owner->changeState(InGame::getInstance(owner));
}

void InMenu::handleUpdate(){
    background.update();
}

void InMenu::handleRendering(){
    sf::RenderWindow *window = WindowInstance;
    background.render();
    window->draw(title);
    window->draw(subtitle);
    window->draw(play);
}

InMenu *InMenu::getInstance(Application *app){
    if(instance == nullptr)
        instance = new InMenu(app);
    return instance;
}




InGame *InGame::instance = nullptr;

InGame::InGame(Application *app) : ApplicationState(app){
    generateFoodPosition();
}

void InGame::generateFoodPosition(){
    std::vector<sf::Vector2i> snakePositions = snake.getPositions();
    std::vector<sf::Vector2i> freePositions;
    for(int line = 0; line < FieldInstance->getSize().y; line++){
        for(int column = 0; column < FieldInstance->getSize().x; column++){
            bool isFree = true;
            sf::Vector2i targetPosition = sf::Vector2i(column, line);
            for(auto position : snakePositions){
                if(position == targetPosition){
                    isFree = false;
                    break;
                }
            }
            if(isFree)
                freePositions.push_back(sf::Vector2i(column, line));
        }
    }
    food.setPosition(freePositions.at(std::rand()%freePositions.size()));
}

void InGame::handleTrasition(){
    if(snake.isAlive() == false){
        owner->changeState(InMenu::getInstance(owner));
        snake.reset();
    }
}

void InGame::handleUpdate(){
    if(snake.eat(food.getPosition()))
        generateFoodPosition();
    snake.update();
}

void InGame::handleRendering(){
    FieldInstance->render();
    food.render();
    snake.render();
}

InGame *InGame::getInstance(Application *app){
    if(instance == nullptr)
        instance = new InGame(app);
    return instance;
}




InEndGame *InEndGame::instance = nullptr;

InEndGame::InEndGame(Application *app) : ApplicationState(app){}

void InEndGame::handleTrasition(){

}

void InEndGame::handleUpdate(){

}

void InEndGame::handleRendering(){

}

InEndGame *InEndGame::getInstance(Application *app){
    if(instance == nullptr)
        instance = new InEndGame(app);
    return instance;
}
