#ifndef APPLICATIONSTATE_H_INCLUDED
#define APPLICATIONSTATE_H_INCLUDED

#include "Application.h"
#include "Snake.h"
#include "Food.h"

class Application;

class ApplicationState {

    private:

    protected:

    Application *owner;

    public:

    ApplicationState(Application *app);

    virtual void handleTrasition() = 0;
    virtual void handleUpdate() = 0;
    virtual void handleRendering() = 0;

};


class InMenu : public ApplicationState {

    private:

    InMenu(Application *app);

    static InMenu *instance;

    public:

    static InMenu *getInstance(Application *app);

    void handleTrasition() override;
    void handleUpdate() override;
    void handleRendering() override;

};

class InGame : public ApplicationState {

    private:

    InGame(Application *app);

    static InGame *instance;

    Snake snake;
    Food food;

    public:

    static InGame *getInstance(Application *app);

    void generateFoodPosition();

    void handleTrasition() override;
    void handleUpdate() override;
    void handleRendering() override;

};

class InEndGame : public ApplicationState {

    private:

    InEndGame(Application *app);

    static InEndGame *instance;

    public:

    static InEndGame *getInstance(Application *app);

    void handleTrasition() override;
    void handleUpdate() override;
    void handleRendering() override;

};


#endif // APPLICATIONSTATE_H_INCLUDED
