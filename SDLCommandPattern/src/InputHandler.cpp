#include "../include/InputHandler.h"

 InputHandler::InputHandler()
 {
    fireClayBrick = new ClayBrickCommand;  
    pourConcreteBrick = new ConcreteBrickCommand;
    castLegoBrick = new LegoBrickCommand;
    sawWoodBrick = new WoodBrickCommand;
 }

void InputHandler::handleInput(SDL_Event* t_gameEvent)
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