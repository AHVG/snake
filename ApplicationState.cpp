#include "ApplicationState.h"
#include "Field.h"

ApplicationState::ApplicationState(Application *app) : owner(app){}


InMenu *InMenu::instance = nullptr;

InMenu::InMenu(Application *app) : ApplicationState(app){}

void InMenu::handleTrasition(){

}

void InMenu::handleUpdate(){

}

void InMenu::handleRendering(){

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
