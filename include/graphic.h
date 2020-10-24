#ifndef __SHAPE_H_
#define __SHAPE_H_

#include <vector>
#include <memory>
#include "nanovg.h"
#include "point.h"

constexpr double pi = 3.14159265358979323846;
using vertices = std::vector<point>;

class _Graphic
{
public:
    enum GraphicType {
        POLYGON,
        CIRCLE
    };
    static std::unique_ptr<_Graphic> create_graphic(GraphicType type);
    virtual void move(float x, float y) = 0;
    virtual void draw(NVGcontext& context) = 0;
};

using Graphic = std::shared_ptr<_Graphic>;

#endif // __SHAPE_H_
