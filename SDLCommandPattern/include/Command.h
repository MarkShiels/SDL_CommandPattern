#pragma Once
#include "../include/ClayFactory.h"
#include "../include/ConcreteFactory.h"
#include "../include/WoodFactory.h"
#include "../include/LegoFactory.h"

class Command
{
public:
    virtual ~Command() {};
    virtual Brick* execute() = 0;
};

class ClayBrickCommand : public Command
{
public:

    Brick* execute() { return factory.NewBrick(); };

private:

    ClayFactory factory;
};

class LegoBrickCommand : public Command
{
public:

    Brick* execute() { return factory.NewBrick(); };

private:

    LegoFactory factory;
};

class ConcreteBrickCommand : public Command
{
public:

    Brick* execute() { return factory.NewBrick(); };

private:

    ConcreteFactory factory;
};

class WoodBrickCommand : public Command
{
public:

    Brick* execute() { return factory.NewBrick(); };

private:

    WoodFactory factory;
};