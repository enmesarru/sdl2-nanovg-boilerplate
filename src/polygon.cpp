#include <cmath>
#include <algorithm>

#include "polygon.h"


Polygon::Polygon(int _numberOfSize, float _x, float _y)
    : numberOfSide(_numberOfSize), x(_x), y(_y), scale(100), angle(22)
{
    this->createSegments();
}

void Polygon::rotate() {
    this->angle += .02;
    this->createSegments();
}

void Polygon::createSegments() {
    if(this->segments.size() > 0) {
        this->segments.clear();
    }
    auto origin = point(this->x, this->y);
    for (double n = 1; n <= this->numberOfSide; n++)
    {
        double pos_x = this->scale * std::sin(2 * pi * n / this->numberOfSide) + this->x;
        double pos_y = this->scale * std::cos(2 * pi  * n / this->numberOfSide) + this->y;
        auto segment = point(pos_x, pos_y);
        segment.rotate(origin, this->angle);
        this->segments.push_back(segment);
    }
}

void Polygon::boundingBox() {
    auto max_x = std::minmax_element(this->segments.begin(), this->segments.end(), 
    [](const point& f, const point& s) {
        return f.x < s.x;
    });

    auto max_y = std::minmax_element(this->segments.begin(), this->segments.end(), 
    [](const point& f, const point& s) {
        return f.y < s.y;
    });

    _boundingBox.x = this->x;
    _boundingBox.y = this->y;
    _boundingBox.w = max_x.second->x - max_x.first->x;
    _boundingBox.h = max_y.second->y - max_y.first->y;
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
        nvgCircle(&context, s.x, s.y, 10.f);
        nvgFillColor(&context, nvgRGBA(5, 74, 145, 255));
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
        nvgStrokeColor(&context, nvgRGBA(241, 115, 0, 255));
        nvgStroke(&context);
    }

    // smallest surrounding rectangle"
    nvgBeginPath(&context);
    auto [x, y, w, h] = _boundingBox;
    nvgRect(&context, x - (w / 2), y - (h / 2), w, h);
    nvgFillColor(&context, nvgRGBA(255,255,255,50));
    nvgFill(&context);
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