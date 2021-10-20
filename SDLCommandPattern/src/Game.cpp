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

    if ( TTF_Init() < 0 ) {
	    std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
    }

    m_renderer = SDL_CreateRenderer(window, -1, 0);
        

    rect.x = 0;
    rect.y = 0;
    rect.w = screenSizeX/2;
    rect.h = screenSizeY/2;

    rect2.x = screenSizeX/2;
    rect2.y = screenSizeY/2;
    rect2.w = screenSizeX/2;
    rect2.h = screenSizeY/2;

    rect3.x = 0;
    rect3.y = screenSizeY/2;
    rect3.w = screenSizeX/2;
    rect3.h = screenSizeY/2;

    rect4.x = screenSizeX/2;
    rect4.y = 0;
    rect4.w = screenSizeX/2;
    rect4.h = screenSizeY/2;

    highman = TTF_OpenFont("../include/highman.ttf", 2500);
    if(!highman)
    {
        std::cout << "error loading highman" <<std::endl;
    }

    white = {255, 255, 255};

    clayMessage.x = 10; 
    clayMessage.y = 0; 
    clayMessage.w = 280; 
    clayMessage.h = 250; 

    legoMessage.x = (screenSizeX / 2) + 10;
    legoMessage.y = screenSizeY / 2;
    legoMessage.w = 280;
    legoMessage.h = 250;

    woodMessage.x = (screenSizeX / 2) + 10;
    woodMessage.y = 0;
    woodMessage.w = 280;
    woodMessage.h = 250;

    concreteMessage.x = 10;
    concreteMessage.y = screenSizeY / 2;
    concreteMessage.w = 280;
    concreteMessage.h = 250;

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
            inputHandler.handleInput(&gameEvent);          
        }
    }
}

void Game::update()
{}

void Game::render()
{

    SDL_RenderClear(m_renderer);

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(m_renderer, &rect);
    SDL_RenderDrawRect(m_renderer, &rect2);
    SDL_RenderDrawRect(m_renderer, &rect3);
    SDL_RenderDrawRect(m_renderer, &rect4);

    messageSurface  = TTF_RenderText_Solid(highman, "Clay Brick", white); 
    messageTxtr = SDL_CreateTextureFromSurface(m_renderer,messageSurface);
    SDL_RenderCopy(m_renderer, messageTxtr, NULL, &clayMessage);   

    messageSurface  = TTF_RenderText_Solid(highman, "Lego Brick", white); 
    messageTxtr = SDL_CreateTextureFromSurface(m_renderer,messageSurface);
    SDL_RenderCopy(m_renderer, messageTxtr, NULL, &legoMessage);
  
    messageSurface  = TTF_RenderText_Solid(highman, "Wood Brick", white); 
    messageTxtr = SDL_CreateTextureFromSurface(m_renderer,messageSurface);
    SDL_RenderCopy(m_renderer, messageTxtr, NULL, &woodMessage);
   
    messageSurface  = TTF_RenderText_Solid(highman, "Concrete Brick", white); 
    messageTxtr = SDL_CreateTextureFromSurface(m_renderer,messageSurface);
    SDL_RenderCopy(m_renderer, messageTxtr, NULL, &concreteMessage);

    SDL_SetRenderDrawColor(m_renderer, 0,0,0, 255);
    SDL_RenderPresent(m_renderer);


}

void Game::cleanUp()
{}