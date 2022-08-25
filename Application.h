#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <vector>
#include <SFML/Graphics.hpp>
#include "ApplicationState.h"

class ApplicationState;
class InMenu;
class InGame;
class InEndGame;

class Application {

    private:

    sf::RenderWindow *window;
    ApplicationState *currentState;

    void handleEvent();
    void handleTrasition();
    void handleUpdate();
    void handleRendering();

    void generateFoodPosition();

    public:

    Application();

    void run();

};


#endif // APPLICATION_H_INCLUDED
