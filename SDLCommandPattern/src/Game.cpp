#include "../include/Game.h"

Game::Game() :
    m_gameIsRunning{ false }
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { // also initialises the events subsystem
        std::cout << "Failed to init SDL.\n";      
    }

    SDL_Window *window = SDL_CreateWindow(
        "Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        680, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if(!window) {
        std::cout << "Failed to create window.\n";}



    fireClayBrick = new ClayBrickCommand; 
        
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
        if(gameEvent.type == SDL_KEYDOWN)
        {
            clayBricks.push_back(fireClayBrick->execute());
            printf("Clay Bricks: ");
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