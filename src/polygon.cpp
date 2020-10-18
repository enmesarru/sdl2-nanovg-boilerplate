#include "polygon.h"

#include <cmath>

std::pair<float, float> rotateByAngle(
    std::pair<float, float> point, 
    std::pair<float, float> origin, 
    float angle)
{
    auto translated = std::make_pair(point.first - origin.first,  point.second - origin.second);
    auto rotated = std::make_pair
    (
        translated.first * std::cos(angle) - translated.second * std::sin(angle),
        translated.first * std::sin(angle) + translated.second * std::cos(angle)
    );
    return std::make_pair(
        rotated.first + origin.first,
        rotated.second + origin.second
    );
}

Polygon::Polygon(int _numberOfSize, float _x, float _y)
    : numberOfSide(_numberOfSize), x(_x), y(_y), scale(100), angle(22)
{
    this->createSegments();
}

void Polygon::rotate() {
    this->angle += 2;
    this->createSegments();
}

void Polygon::createSegments() {
    if(this->segments.size() > 0) {
        this->segments.clear();
    }
    auto origin = std::make_pair(x, y);
    for (double n = 0; n < this->numberOfSide; n++)
    {
        double pos_x = this->scale * std::sin(2 * pi * n / this->numberOfSide) + this->x;
        double pos_y = this->scale * std::cos(2 * pi  * n / this->numberOfSide) + this->y;
        auto pair = std::make_pair(pos_x, pos_y);
        auto rotated = rotateByAngle(pair, origin, this->angle);
        this->segments.push_back(rotated);
    }
}

void Polygon::scaleUp() {
    this->scale += 10;
    this->createSegments();
}

void Polygon::scaleDown() {
    this->scale -= 10;
    this->createSegments();
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