#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include <vector>
#include "graphic.h"
#include "nanovg.h"

class Circle: public _Graphic
{
public:
    Circle(float radius, float x, float y);
    void move(float x, float y);
    void draw(NVGcontext& context);
    void boundingBox();
    vertices& getSegments();
    float getRadius();
private:
    float radius, x, y;
    vertices segments;
};

#endif