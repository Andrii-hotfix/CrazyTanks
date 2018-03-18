#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <algorithm>

using namespace std;

Game::Game() :
    map(60, 25)
{
    srand(time(nullptr));
    vector<Wall*> walls = generateWalls(60, 25);
    while (!wallsGoodPos(walls)) {
        for (Wall* wall: walls) {
            delete wall;
        }
        walls.clear();
        walls = generateWalls(60, 25);
    }
   map.redraw();
   for (Wall* wall: walls) {
       wall->redraw();
   }
}

bool Game::intersects(int ax, int ay, int ax1, int ay1,
                      int bx, int by, int bx1, int by1)
{
    bool xIntersection = !(ax1 < bx || ax > bx1);
    bool yIntersection = !(ay1 < by || ay > by1);
    return xIntersection && yIntersection;
}

bool Game::wallsGoodPos(vector<Wall*> randomWalls)
{
    for (Wall* iWall: randomWalls) {
        for (Wall* jWall: randomWalls) {
            if (iWall != jWall) {
                int ax  = iWall->getX();
                int ay  = iWall->getY();
                int ax1 = ax + iWall->getWidth();
                int ay1 = ay + iWall->getLength();
                int bx  = jWall->getX();
                int by  = jWall->getY();
                int bx1 = bx + jWall->getWidth();
                int by1 = by + jWall->getLength();
                if (intersects(ax, ay, ax1, ay1, bx, by, bx1, by1)) {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<Wall*> Game::generateWalls(int mapWidth, int mapLength)
{
    vector<Wall*> walls;
    for (int i = 0; i < 7; i++) {
        int wallLength = (rand() % 9) + 1;
        int x = rand() % (mapWidth - 3);
        int y = rand() % (mapLength - wallLength);
        Wall* newWall = new Wall(x, y, wallLength);
        if ((x + wallLength) < mapLength) {
            newWall->rotate();
        }
        walls.push_back(newWall);
    }
    return walls;
}
