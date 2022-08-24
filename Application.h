#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Snake.h"

class Application {

    private:

    sf::RenderWindow *window;
    Snake snake;

    void handleEvent();
    void handleUpdate();
    void handleRendering();

    public:

    Application();

    void run();

};

#endif // APPLICATION_H_INCLUDED
