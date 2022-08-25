#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <vector>
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"

class Application {

    private:

    sf::RenderWindow *window;
    Snake snake;
    Food food;

    void handleEvent();
    void handleUpdate();
    void handleRendering();

    void generateFoodPosition();

    public:

    Application();

    void run();

};

#endif // APPLICATION_H_INCLUDED
