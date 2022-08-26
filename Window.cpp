#include "Window.h"

Window *Window::instance = nullptr;

Window::Window() : window(new sf::RenderWindow(sf::VideoMode(420, 420), "Snake")){}

Window *Window::getInstance(){
    if(instance == nullptr)
        instance = new Window;
    return instance;
}

sf::RenderWindow *Window::getWindow() const{
    return window;
}
