#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Window.h"
#include "Application.h"
#include "Field.h"

Application::Application(){
    window = WindowInstance;
    std::srand(time(NULL));
    generateFoodPosition();
}

void Application::run(){
    while(window->isOpen()){
        handleEvent();
        handleUpdate();
        handleRendering();
    }
}

void Application::handleEvent(){
    sf::Event event;
    while (window->pollEvent(event))
        if (event.type == sf::Event::Closed)
            window->close();
}

void Application::handleUpdate(){
    if(snake.eat(food.getPosition()))
        generateFoodPosition();
    snake.update();
}

void Application::handleRendering(){
    window->clear();
    FieldInstance->render();
    food.render();
    snake.render();
    window->display();
}

void Application::generateFoodPosition(){
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

