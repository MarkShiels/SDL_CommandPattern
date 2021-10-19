#include "../include/Game.h"

Game::Game() :
    m_gameIsRunning{ false }
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { // also initialises the events subsystem
        std::cout << "Failed to init SDL.\n";      
    }

    SDL_Window *window = SDL_CreateWindow(
        "Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        screenSizeX, screenSizeY, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if(!window) {
        std::cout << "Failed to create window.\n";}

    fireClayBrick = new ClayBrickCommand; 
    pourConcreteBrick = new ConcreteBrickCommand;
    sawWoodBrick = new WoodBrickCommand;
    castLegoBrick = new LegoBrickCommand;
        
}
    
Game::~Game()
{
    cleanUp();
}
    
void Game::run()
{
    SDL_Event gameEvent;

    m_gameIsRunning = true;
    while (m_gameIsRunning)
    {
        processEvents(gameEvent);
        update();
        render();
    }
}

void Game::processEvents(SDL_Event gameEvent)
{
    while (SDL_PollEvent(&gameEvent) != 0)
    { 
        if(gameEvent.type == SDL_MOUSEBUTTONUP)
        {
            int mPosX, mPosY;
            SDL_GetMouseState(&mPosX, &mPosY);

            if(mPosX < screenSizeX / 2 && mPosY < screenSizeY /2)
            {
                clayBricks.push_back(fireClayBrick->execute());
                std::string brickNum = std::to_string(clayBricks.size());
                std::string numBricks = "Clay Bricks: " + brickNum;
                std::cout << numBricks.c_str() << std::endl;
            }
            else if(mPosX < screenSizeX / 2 && mPosY > screenSizeY /2)
            {
                concreteBricks.push_back(pourConcreteBrick->execute());
                std::string brickNum = std::to_string(concreteBricks.size());
                std::string numBricks = "Concrete Bricks: " + brickNum;
                std::cout << numBricks.c_str() << std::endl;
            }
            else if(mPosX > screenSizeX / 2 && mPosY < screenSizeY /2)
            {
                woodBricks.push_back(sawWoodBrick->execute());
                std::string brickNum = std::to_string(woodBricks.size());
                std::string numBricks = "Wood Bricks: " + brickNum;
                std::cout << numBricks.c_str() << std::endl;
            }
            else if(mPosX > screenSizeX / 2 && mPosY > screenSizeY /2)
            {
                legoBricks.push_back(castLegoBrick->execute());
                std::string brickNum = std::to_string(legoBricks.size());
                std::string numBricks = "Lego Bricks: " + brickNum;
                std::cout << numBricks.c_str() << std::endl;
            }
        }
    }
}

void Game::update()
{
    // printf("update");
}

void Game::render()
{

}

void Game::cleanUp()
{
    
}