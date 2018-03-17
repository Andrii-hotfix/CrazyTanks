#ifndef WALL_H
#define WALL_H

#include "gameobject.h"

const int wallWidth = 3;

class Wall : public GameObject
{

public:
    Wall(int x, int y, int length);
    ~Wall();
    void rotate();
};

#endif // WALL_H
