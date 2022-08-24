#include "Window.h"
#include "Application.h"

Application::Application(){
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
    {
        if (event.type == sf::Event::Closed){
            window->close();
        }
    }
}

void Application::handleUpdate(){
    snake.update();
}

void Application::handleRendering(){
    window->clear();
    snake.render();
    window->display();
}


