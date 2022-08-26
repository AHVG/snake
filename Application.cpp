#include <iostream>
#include <time.h>
#include "Window.h"
#include "Application.h"
#include "Field.h"

Application::Application(){
    window = WindowInstance;
    std::srand(time(NULL));
    currentState = InMenu::getInstance(this);
}

void Application::run(){
    while(window->isOpen()){
        handleEvent();
        handleTrasition();
        handleUpdate();
        handleRendering();
    }
}

void Application::changeState(ApplicationState *newState){
    currentState = newState;
}

void Application::handleEvent(){
    sf::Event event;
    while (window->pollEvent(event))
        if (event.type == sf::Event::Closed)
            window->close();
}

void Application::handleTrasition(){
    currentState->handleTrasition();
}

void Application::handleUpdate(){
    currentState->handleUpdate();
}

void Application::handleRendering(){
    window->clear();
    currentState->handleRendering();
    window->display();
}

