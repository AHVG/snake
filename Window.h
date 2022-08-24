#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SFML/Graphics.hpp>

class Window {

    private:

    static Window *instance;
    sf::RenderWindow *window;

    Window();
    ~Window();

    public:

    static Window *getInstance();
    sf::RenderWindow *getWindow() const;

};

#define WindowInstance Window::getInstance()->getWindow()

#endif // WINDOW_H_INCLUDED
