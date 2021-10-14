#include <SDL2/SDL.h>
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

    Command* fireClayBrick;
    std::vector<Brick*> clayBricks;
    bool m_gameIsRunning;

};