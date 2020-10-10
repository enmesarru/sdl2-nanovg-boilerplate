#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <vector>
#include "graphic.h"

class Canvas
{
public:
    void add(Graphic& graph);
    void remove(Graphic& graph);
    Canvas();
    ~Canvas();
private:
    std::vector<Graphic> children;
};

#endif