#include <SDL.h>
#include <iostream>
#include "../include/LegoFactory.h"
#include "../include/ClayFactory.h"
#include "../include/ConcreteFactory.h"
#include "../include/Command.h"

class Game
{
public:

    Game();
    ~Game();
    void run();

private:

    void processEvents(SDL_Event event);
    void update();
    void render();

    void cleanUp();

    bool m_gameIsRunning;
    float screenSizeX = 680;
    float screenSizeY = 480;
    
    Command* fireClayBrick;
    std::vector<Brick*> clayBricks;
    Command* pourConcreteBrick;
    std::vector<Brick*> concreteBricks;
    Command* castLegoBrick;
    std::vector<Brick*> legoBricks;
    Command* sawWoodBrick;
    std::vector<Brick*> woodBricks;

};