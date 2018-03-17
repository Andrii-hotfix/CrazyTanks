#include "wall.h"
#include <iostream>

Wall::Wall(int x, int y, int length) :
    GameObject(x, y, wallWidth, length)
{
    draw();
}

void Wall::rotate()
{    
    destroy();
    int width = getWidth();
    int length = getLength();
    setWidth(length * 2);
    setLength(width / 2);
    draw();
}

Wall::~Wall()
{
    destroy();
}
