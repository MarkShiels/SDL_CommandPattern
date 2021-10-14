#ifndef FACTORY_H
#define FACTORY_H
#pragma Once
#include <vector>
#include "../include/Brick.h"

class Factory
{
public:
    
    Factory(){};
    virtual ~Factory(){};
    virtual Brick* NewBrick() = 0;

};
#endif 
