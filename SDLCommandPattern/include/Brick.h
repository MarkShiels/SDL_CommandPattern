#pragma Once
#include <SDL2/SDL.h>
#include <iostream>
class Brick
{
public:

    Brick(){};
    virtual ~Brick(){};
    virtual void Draw() = 0;

};

class LegoBrick : public Brick
{
public:

    LegoBrick(){};
    ~LegoBrick(){};

    void Draw() 
    {
        std::cout << "New Lego Brick" << std::endl;
    };
};

class ClayBrick : public Brick
{
public:

    ClayBrick(){};
    ~ClayBrick(){};

    void Draw() 
    {
        std::cout << "New Clay Brick" << std::endl;
    };
};

class ConcreteBrick : public Brick
{
public:

    ConcreteBrick(){};
    ~ConcreteBrick(){};

    void Draw() 
    {
        std::cout << "New Concrete Brick" << std::endl;
    };
};