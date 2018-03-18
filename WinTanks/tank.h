#ifndef TANK_H
#define TANK_H

#include "gameobject.h"

class Tank : public GameObject
{
public:
    Tank(int x, int y, char paint);
    ~Tank();
    void redraw();

protected:
    void draw();
    void destroy();

private:
    char paint;
};

#endif // TANK_H
