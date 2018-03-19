#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <algorithm>

using namespace std;

Game::Game() :
    map(new Map(60, 25))
{
    srand(time(NULL));
    int heroX = (map->getX() + map->getWidth()) / 2;
    int heroY = map->getY() + map->getLength() - 3;
    hero = new Tank(heroX, heroY, HERO_PAINT);
    generateWalls();
    generateEnemies();
    vector<GameObject*> mapObjects;
    for (Wall* wall: walls) {
        mapObjects.push_back(wall);
    }
    for (Tank* enemy: enemies) {
        mapObjects.push_back(enemy);
    }
    mapObjects.push_back(hero);
    while (!wallsGoodPos(mapObjects)) {
        for (Wall* wall: walls) {
            delete wall;
        }
        for (Tank* enemy: enemies) {
            delete enemy;
        }
        walls.clear();
        enemies.clear();
        mapObjects.clear();
        generateWalls();
        generateEnemies();
        for (Wall* wall: walls) {
            mapObjects.push_back(wall);
        }
        for (Tank* enemy: enemies) {
            mapObjects.push_back(enemy);
        }
        mapObjects.push_back(hero);
    }
   for (Wall* wall: walls) {
       wall->redraw();
   }
   for (Tank* enemy: enemies) {
       enemy->redraw();
   }
   hero->redraw();
   map->redraw();
}

Game::~Game()
{
    for (Wall* wall: walls) {
        delete wall;
    }
    delete map;
    delete hero;
    for (Tank* enemy: enemies) {
        delete enemy;
    }
}

bool Game::intersects(int ax, int ay, int ax1, int ay1,
                      int bx, int by, int bx1, int by1)
{
    bool xIntersection = !(ax1 < bx || ax > bx1);
    bool yIntersection = !(ay1 < by || ay > by1);
    return xIntersection && yIntersection;
}

bool Game::wallsGoodPos(vector<GameObject*> objects)
{
    for (GameObject* iObject: objects) {
        for (GameObject* jObject: objects) {
            if (iObject != jObject) {
                int ax  = iObject->getX();
                int ay  = iObject->getY();
                int ax1 = ax + iObject->getWidth();
                int ay1 = ay + iObject->getLength();
                int bx  = jObject->getX();
                int by  = jObject->getY();
                int bx1 = bx + jObject->getWidth();
                int by1 = by + jObject->getLength();
                if (intersects(ax, ay, ax1, ay1, bx, by, bx1, by1)) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Game::generateWalls()
{
    for (int i = 0; i < 7; i++) {
        int wallLength = (rand() % 9) + 1;
        int x = (rand() % (MAP_WIDTH - 1 - 3)) + 1;
        int y = (rand() % (MAP_LENGTH - 1 - wallLength)) + 1;
        Wall* newWall = new Wall(x, y, wallLength);
        if ((x + wallLength) < MAP_LENGTH) {
            newWall->rotate();
        }
        walls.push_back(newWall);
    }
}

void Game::generateEnemies()
{
    for (int i = 0; i < 3; i++) {
        int x = (rand() % (MAP_WIDTH - 1 - 3)) + 1;
        int y = (rand() % (MAP_LENGTH - 1 - 3)) + 1;
        enemies.push_back(new Tank(x, y, ENEMY_PAINT));
    }
}
