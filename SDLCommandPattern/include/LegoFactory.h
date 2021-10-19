#ifndef LEGO_FACTORY_H
#define LEGO_FACTORY_H
#include "../include/Factory.h"

class LegoFactory : public Factory
{
public:

    LegoFactory();
    ~LegoFactory();

    Brick* NewBrick();
   
};
#endif