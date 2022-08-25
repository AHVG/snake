#include "Window.h"
#include "Application.h"
#include "Field.h"

Application::Application() : food(sf::Vector2i(10,10)){
    window = WindowInstance;
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
    if(snake.ate(food.getPosition())){
        generateApplePosition(snake.getPositions());
    }
    snake.update();
}

void Application::handleRendering(){
    window->clear();
    FieldInstance->render();
    food.render();
    snake.render();
    window->display();
}

void Application::generateApplePosition(std::vector<sf::Vector2i> snakePositions){

}

