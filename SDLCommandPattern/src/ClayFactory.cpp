#pragma Once
#include "../include/ClayFactory.h"

ClayFactory::ClayFactory()
{}

ClayFactory::~ClayFactory()
{}

Brick* ClayFactory::NewBrick()
{
    return new ClayBrick;
}