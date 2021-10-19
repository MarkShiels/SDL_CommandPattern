#pragma Once
#include "../include/WoodFactory.h"

WoodFactory::WoodFactory()
{}

WoodFactory::~WoodFactory()
{}

Brick* WoodFactory::NewBrick()
{
    return new WoodBrick;
}