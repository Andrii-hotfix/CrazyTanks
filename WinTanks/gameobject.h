#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <windows.h>

class GameObject
{
public:
    GameObject(int x, int y, int width, int length);

    int getWidth() const;
    int getHeigth() const;
    int getX() const;
    int getY() const;

    virtual void rotate();

protected:
    BOOL setXY(int x, int y);
    void draw();
    void destroy();

private:
    int x;
    int y;
    int width;
    int length;
};

#endif // GAMEOBJECT_H
