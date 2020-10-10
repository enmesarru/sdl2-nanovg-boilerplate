#include <iostream>
#include <cmath>    
#include "circle.h"

Circle::Circle(float _radius, float _x, float _y)
    : radius(_radius) , x(_x), y(_y)
{
    for (double theta = 0; theta < 2 * pi; theta+= 0.1)
    {
        segments.push_back(std::make_pair(
            radius * std::sin(theta) + x,
            radius * std::cos(theta) + y
        ));
    }
}

void Circle::draw() {
    std::cout << "draw executed\n";
}

float Circle::getRadius() {
    return radius;
}


void Circle::move(float x, float y) {
    std::cout << "moved to x:" << x << " y:" << y << '\n';
}

vertices& Circle::getSegments() {
    return segments;
} 