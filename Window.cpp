#include "Window.h"

Window *Window::instance = nullptr;

Window::Window() : window(new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!")){}

Window *Window::getInstance(){
    if(instance == nullptr)
        instance = new Window;
    return instance;
}

sf::RenderWindow *Window::getWindow() const{
    return window;
}

Window::~Window(){
    if(instance != nullptr){
        delete instance;
        delete window;
    }
}


