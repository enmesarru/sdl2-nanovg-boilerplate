#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include <vector>
#include "graphic.h"

using vertices = std::vector<std::pair<float, float>>;
class Circle: public Graphic
{
public:
    Circle(float radius, float x, float y);
    void move(float x, float y);
    void draw();
    vertices& getSegments();
    float getRadius();
private:
    float radius, x, y;
    vertices segments;
};

#endif