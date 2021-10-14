#pragma Once
#include "../include/LegoFactory.h"

LegoFactory::LegoFactory()
{}

LegoFactory::~LegoFactory()
{}

Brick* LegoFactory::NewBrick()
{
    return new LegoBrick;
}