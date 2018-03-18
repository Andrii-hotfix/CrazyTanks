#include "map.h"

Map::Map(int width, int heigth) :
    GameObject(0, 0, width, heigth)
{
    draw();
}

Map::~Map()
{
    destroy();
}
