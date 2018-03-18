#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <windows.h>

class GameObject
{
public:
    GameObject(int x, int y, int width, int length);
    GameObject();

    int getWidth() const;
    int getLength() const;
    int getX() const;
    int getY() const;

    void redraw();

protected:
    BOOL setCursor(int x, int y);
    void setWidth(int newWidth);
    void setLength(int newLength);
    void setX(int newX);
    void setY(int newY);
    virtual void draw();
    virtual void destroy();

private:
    int x;
    int y;
    int width;
    int length;
};

#endif // GAMEOBJECT_H
