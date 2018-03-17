#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

Game::Game() :
    map(60, 25)
{
    srand(time(nullptr));
    bool rightWallsPos = false;t
//    while (!rightWallsPos) {
//        for (int i = 0; i < 5; i++) {
//            int x = rand() % (60 - 3);
//            int y = rand() % (25 - 10);
//            walls[i] = new Wall(x, y, 10);
//        }

//        rightWallsPos = true;
//        for (int i = 0; i < 5; i++) {
//            for (int j = 0; j < 5; j++) {
//                if (i == j) {
//                    continue;
//                }
//                int ax  = walls[i]->getX();
//                int ay  = walls[i]->getY();
//                int ax1 = ax + walls[i]->getWidth();
//                int ay1 = ay + walls[i]->getLength();
//                int bx  = walls[j]->getX();
//                int by  = walls[j]->getY();
//                int bx1 = bx + walls[j]->getWidth();
//                int by1 = by + walls[j]->getLength();
//                if (intersects(ax, ay, ax1, ay1, bx, by, bx1, by1)) {
//                    for (Wall* wall: walls) {
//                        delete wall;
//                        wall = nullptr;
//                    }
//                    rightWallsPos = false;
//                    break;
//                }
//            }
//        }
//    }

    map.redraw();
    for (Wall* wall: walls) {
        wall->redraw();
    }
}

void Game::exec()
{
//  Wall a(1, 1, 20);
//  cin.ignore();
//  a.rotate();
}

bool Game::intersects(int ax, int ay, int ax1, int ay1,
                      int bx, int by, int bx1, int by1)
{
    bool xIntersection = !(ax1 < bx || ax > bx1);
    bool yIntersection = !(ay1 < by || ay > by1);
    return xIntersection && yIntersection;
}
