#include <iostream>
#include <cmath>
#include "circle.h"

Circle::Circle(float _radius, float _x, float _y)
    : radius(_radius), x(_x), y(_y)
{
    for (double theta = 0; theta < 2 * pi; theta += 0.1)
    {
        segments.push_back(point(
            radius * std::sin(theta) + x,
            radius * std::cos(theta) + y));
    }
}

void Circle::boundingBox() {}

void Circle::draw(NVGcontext &context)
{
    for (auto &&s : segments)
    {
        nvgBeginPath(&context);
        nvgCircle(&context, s.x, s.y, 2.f);
        nvgFillColor(&context, nvgRGBA(255, 192, 0, 255));
        nvgFill(&context);
    }

    for (size_t i = 0; i < segments.size(); ++i)
    {
        nvgBeginPath(&context);
        if (i == segments.size() - 1)
        {
            nvgMoveTo(&context, segments[0].x, segments[0].y);
            nvgLineTo(&context, segments[i].x, segments[i].y);
        }
        else
        {
            nvgMoveTo(&context, segments[i].x, segments[i].y);
            nvgLineTo(&context, segments[i + 1].x, segments[i + 1].y);
        }
        nvgStrokeWidth(&context, 2);
        nvgStrokeColor(&context, nvgRGBA(0, 127, 0, 255));
        nvgStroke(&context);
    }
}

float Circle::getRadius()
{
    return radius;
}

void Circle::move(float x, float y)
{
    std::cout << "moved to x:" << x << " y:" << y << '\n';
}

vertices &Circle::getSegments()
{
    return segments;
}