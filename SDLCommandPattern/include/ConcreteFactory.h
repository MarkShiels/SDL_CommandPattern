#pragma Once
#include "../include/Factory.h"

class ConcreteFactory : public Factory
{
public:

    ConcreteFactory();
    ~ConcreteFactory();

    Brick* NewBrick();
   
};