#ifndef CLAY_FACTORY_H
#define CLAY_FACTORY_H
#include "../include/Factory.h"

class ClayFactory : public Factory
{
public:

    ClayFactory();
    ~ClayFactory();

    Brick* NewBrick();
   
};
#endif