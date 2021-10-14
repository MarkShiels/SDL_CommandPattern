#pragma Once
#include "../include/ConcreteFactory.h"

ConcreteFactory::ConcreteFactory()
{}

ConcreteFactory::~ConcreteFactory()
{}

Brick* ConcreteFactory::NewBrick()
{
    return new ConcreteBrick;
}