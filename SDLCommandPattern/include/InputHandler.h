#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "../include/LegoFactory.h"
#include "../include/ClayFactory.h"
#include "../include/ConcreteFactory.h"
#include "../include/WoodFactory.h"
#include "../include/Command.h"

class InputHandler
{
public:

    InputHandler();
    ~InputHandler(){};


    void handleInput(SDL_Event* t_gameEvent);

private:

    Command* fireClayBrick;  
    Command* pourConcreteBrick;
    Command* castLegoBrick;
    Command* sawWoodBrick;
    std::vector<Brick*> clayBricks;
    std::vector<Brick*> concreteBricks;
    std::vector<Brick*> legoBricks;
    std::vector<Brick*> woodBricks;

    float screenSizeX = 680;
    float screenSizeY = 480;

};

#endif