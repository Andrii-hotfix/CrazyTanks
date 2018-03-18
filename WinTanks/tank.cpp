#include "tank.h"
#include "gameobject.h"
#include <iostream>

using namespace std;

Tank::Tank(int x, int y, char paint) :
    GameObject(x, y, 3, 3), paint(paint)
{
    draw();
}

Tank::~Tank()
{
    destroy();
}

void Tank::draw()
{
    setCursor(getX(), getY());
    for (int i = 0; i < getWidth(); i++) {
        for (int j = 0; j < getLength(); j++) {
            cout << paint;
        }
        setCursor(getX(), getY() + i);
    }
    setCursor(0, 26);
}

void Tank::destroy()
{
    setCursor(getX(), getY());
    for (int i = 0; i < getWidth(); i++) {
        for (int j = 0; j < getLength(); j++) {
            cout << ' ';
        }
        setCursor(getX(), getY() + i);
    }
    setCursor(0, 26);
}

void Tank::redraw()
{
    destroy();
    draw();
}


