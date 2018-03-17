#ifndef WALL_H
#define WALL_H

#include "gameobject.h"

const int wallWidth = 5;

class Wall : public GameObject
{

public:
    Wall(int x, int y, int length);
    void rotate();
};

#endif // WALL_H
