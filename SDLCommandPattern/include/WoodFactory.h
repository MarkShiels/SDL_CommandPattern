#ifndef WOOD_FACTORY_H
#define WOOD_FACTORY_H
#include "../include/Factory.h"

class WoodFactory : public Factory
{
public:

    WoodFactory();
    ~WoodFactory();

    Brick* NewBrick();
   
};
#endif