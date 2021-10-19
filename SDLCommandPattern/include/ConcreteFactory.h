#ifndef CONCRETE_FACTORY_H
#define CONCRETE_FACTORY_H
#include "../include/Factory.h"

class ConcreteFactory : public Factory
{
public:

    ConcreteFactory();
    ~ConcreteFactory();

    Brick* NewBrick();
   
};
#endif