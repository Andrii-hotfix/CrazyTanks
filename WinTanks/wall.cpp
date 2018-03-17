#include "wall.h"

Wall::Wall(int x, int y, int length) :
    GameObject(x, y, wallWidth, length)
{
    draw();
}

void Wall::rotate()
{
    destroy();
    int tmp = x;
    x = y;
    y = tmp;
    draw();
}
