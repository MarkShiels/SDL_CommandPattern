#pragma Once
#include "ClayFactory.h"

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