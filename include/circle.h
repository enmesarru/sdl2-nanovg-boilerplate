#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include <vector>
#include "graphic.h"
#include "nanovg.h"

class Circle: public Graphic
{
public:
    Circle(float radius, float x, float y);
    void move(float x, float y);
    void draw(NVGcontext& context);
    vertices& getSegments();
    float getRadius();
private:
    float radius, x, y;
    vertices segments;
};

#endif