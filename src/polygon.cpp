#include "polygon.h"

#include <cmath>



double degreeToRadian(double degree) 
{ 
    return (degree * (180 / pi)); 
} 

Polygon::Polygon(int _numberOfSize, float _x, float _y)
    : numberOfSide(_numberOfSize), x(_x), y(_y)
{
    this->createSegments();
}

void Polygon::createSegments() {
    if(this->segments.size() > 0) {
        this->segments.clear();
    }

    for (double n = 0; n < this->numberOfSide; n++)
    {
        double pos_x = 100 * std::sin(2 * pi * n / this->numberOfSide) + this->x;
        double pos_y = 100 * std::cos(2 * pi  * n / this->numberOfSide) + this->y;
        auto pair = std::make_pair(pos_x, pos_y);
        this->segments.push_back(pair);
    }
}

void Polygon::draw(NVGcontext &context)
{

    for (auto &&s : segments)
    {
        nvgBeginPath(&context);
        nvgCircle(&context, s.first, s.second, 10.f);
        nvgFillColor(&context, nvgRGBA(5, 74, 145, 255));
        nvgFill(&context);
    }

    for (size_t i = 0; i < segments.size(); ++i)
    {
        nvgBeginPath(&context);
        if (i == segments.size() - 1)
        {
            nvgMoveTo(&context, segments[0].first, segments[0].second);
            nvgLineTo(&context, segments[i].first, segments[i].second);
        }
        else
        {
            nvgMoveTo(&context, segments[i].first, segments[i].second);
            nvgLineTo(&context, segments[i + 1].first, segments[i + 1].second);
        }
        nvgStrokeWidth(&context, 2);
        nvgStrokeColor(&context, nvgRGBA(241, 115, 0, 255));
        nvgStroke(&context);
    }
}

void Polygon::move(float x, float y)
{
}

void Polygon::incrementSide() {
    this->numberOfSide++;
    this->createSegments();
}

vertices &Polygon::getSegments()
{
    return segments;
}