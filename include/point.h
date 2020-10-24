#ifndef __POINT_H_
#define __POINT_H_

class point
{
public:
    point(float _x, float _y);
    ~point();
    void rotate(point origin, const float angle);
    float x, y;
};

#endif