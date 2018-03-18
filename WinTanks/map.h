#ifndef MAP_H
#define MAP_H

#include "gameobject.h"

class Map : public GameObject
{
public:
    Map(int width, int heigth);
    ~Map();
};

#endif // MAP_H
