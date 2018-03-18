#ifndef GAME_H
#define GAME_H

#include "wall.h"
#include "map.h"
#include "tank.h"
#include <vector>

const int MAP_WIDTH = 60;
const int MAP_LENGTH = 25;
const char ENEMY_PAINT = char(178);
const char HERO_PAINT = char(219);

using namespace std;

class Game
{
public:
    Game();
    ~Game();
    bool intersects(int ax, int ay, int ax1, int ay1,
                    int bx, int by, int bx1, int by1);
    bool wallsGoodPos(std::vector<GameObject*> randomWalls);
    void generateWalls();
    void generateEnemies();

private:
    Map* map;
    std::vector<Wall*> walls;
    std::vector<Tank*> enemies;
    Tank* hero;
};

#endif // GAME_H
