#ifndef GAME_H
#define GAME_H

#include "wall.h"
#include "map.h"

class Game
{
public:
    Game();
    void exec();

private:
    Wall* walls;
};

#endif // GAME_H
