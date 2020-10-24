#include "point.h"
#include <math.h>

point::point(float _x, float _y)
    : x(_x), y(_y)
{
}

point::~point()
{
}

void point::rotate(point origin, const float angle) {
    float s = std::sin(angle);
    float c = std::cos(angle);

    this->x -= origin.x;
    this->y -= origin.y;
    // rotate point
    float xnew = this->x * c - this->y * s;
    float ynew = this->x * s + this->y * c;

    // translate point back:
    this->x = xnew + origin.x;
    this->y = ynew + origin.y;
}