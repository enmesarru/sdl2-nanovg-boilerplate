#ifndef __SHAPE_H_
#define __SHAPE_H_

constexpr double pi = 3.14159265358979323846;

class Graphic
{
public:
    virtual void move(float x, float y) = 0;
    virtual void draw() = 0;
};

#endif // __SHAPE_H_
