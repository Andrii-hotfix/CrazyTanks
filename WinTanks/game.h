#ifndef GAME_H
#define GAME_H

#include "wall.h"
#include "map.h"
#include <vector>

class Game
{
public:
    Game();
    bool intersects(int ax, int ay, int ax1, int ay1,
                    int bx, int by, int bx1, int by1);
    bool wallsGoodPos(std::vector<Wall*> randomWalls);
    std::vector<Wall*> generateWalls(int mapWidth, int mapLength);

private:
    Map map;
    std::vector<Wall*> walls;
};

#endif // GAME_H
