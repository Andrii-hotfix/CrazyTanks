#include "gameobject.h"
#include <iostream>

using namespace std;

GameObject::GameObject(int x, int y, int width, int length) :
    x(x),
    y(y),
    width(width),
    length(length) {}

BOOL GameObject::setCursor(int x, int y)
{
    COORD c = {x, y};
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void GameObject::draw()
{
    setCursor(x,y);
    cout << char(201);
    for (int i = 1; i < width; i++) {
        cout << char(205);
    }
    cout << char(187);
    setCursor(x, length + y);
    cout << char(200);
    for (int i = 1; i < width; i++) {
        cout << char(205);
    }
    cout << char(188);
    for (int i = y + 1; i < length + y; i++) {
        setCursor(x, i);
        cout << char(186);
        setCursor(x + width, i);
        cout << char(186);
    }
    setCursor(0, 26);
}

void GameObject::destroy()
{
    setCursor(x, y);
    cout << ' ';
    for (int i = 1; i < width; i++) {
        cout << ' ';
    }
    cout << ' ';
    setCursor(x, length + y);
    cout << ' ';
    for (int i = 1; i < width; i++) {
        cout << ' ';
    }
    cout << ' ';
    for (int i = y + 1; i < length + y; i++) {
        setCursor(x, i);
        cout << ' ';
        setCursor(x + width, i);
        cout << ' ';
    }

}

int GameObject::getWidth() const
{
    return width;
}

int GameObject::getLength() const
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

void GameObject::setX(int newX)
{
    x = newX;
    redraw();
}

void GameObject::setY(int newY)
{
    y = newY;
    redraw();
}

void GameObject::setLength(int newLength)
{
    length = newLength;
}

void GameObject::setWidth(int newWidth)
{
    width = newWidth;
}

void GameObject::redraw()
{
    destroy();
    draw();
}
