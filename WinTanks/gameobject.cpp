#include "gameobject.h"
#include <iostream>

using namespace std;

GameObject::GameObject(int x, int y, int width, int length) :
    x(x),
    y(y),
    width(width),
    length(length) {}

BOOL GameObject::setXY(int x, int y)
{
    COORD c = {x, y};
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void GameObject::draw()
{
    setXY(x,y);
    cout << char(201);
    for (int i = 1; i < width; i++) {
        cout << char(205);
    }
    cout << char(187);
    setXY(x, length + y);
    cout << char(200);
    for (int i = 1; i < width; i++) {
        cout << char(205);
    }
    cout << char(188);
    for (int i = y + 1; i < length + y; i++) {
        setXY(x, i);
        cout << char(186);
        setXY(x + width, i);
        cout << char(186);
    }
}

void GameObject::destroy()
{
    setXY(x, y);
    cout << ' ';
    for (int i = 1; i < width; i++) {
        cout << ' ';
    }
    cout << ' ';
    setXY(x, length + y);
    cout << ' ';
    for (int i = 1; i < width; i++) {
        cout << ' ';
    }
    cout << ' ';
    for (int i = y + 1; i < length + y; i++) {
        setXY(x, i);
        cout << ' ';
        setXY(x + width, i);
        cout << ' ';
    }

}

int GameObject::getWidth() const
{
    return width;
}

int GameObject::getHeigth() const
{
    return length;
}

int GameObject::getX() const
{
    return x;
}

int GameObject::getY() const
{
    return y;
}
