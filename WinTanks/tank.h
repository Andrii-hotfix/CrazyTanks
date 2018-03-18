#ifndef TANK_H
#define TANK_H

#include "gameobject.h"

class Tank : public GameObject
{
public:
    Tank(int x, int y);

protected:
    draw() override;
};

#endif // TANK_H
