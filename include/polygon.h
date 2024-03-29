#ifndef __POLYGON_H_
#define __POLYGON_H_

#include <vector>
#include "graphic.h"
#include "nanovg.h"

class Polygon: public _Graphic
{
public:
    Polygon(int numberOfSide, float x, float y);
    void move(float x, float y);
    void draw(NVGcontext& context);
    void boundingBox();
    void incrementSide();
    vertices& getSegments();
    void scaleUp();
    void scaleDown();
    void rotate();
private:
    float x, y;
    void createSegments();
    int numberOfSide;
    vertices segments;
    double scale;
    float angle;
};

#endif