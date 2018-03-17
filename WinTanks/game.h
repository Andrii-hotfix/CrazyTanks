#ifndef GAME_H
#define GAME_H

#include "wall.h"
#include "map.h"

class Game
{
public:
    Game();
    void exec();
    bool intersects(int ax, int ay, int ax1, int ay1,
                    int bx, int by, int bx1, int by1);

private:
    Map map;
    Wall* walls[5];
};

#endif // GAME_H
