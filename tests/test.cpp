#include <gtest/gtest.h>
#include "point.h"


TEST(Point, ConvexHull) {
    std::vector<point> points;
    points.push_back(point(726, 334));
    points.push_back(point(553, 334));
    points.push_back(point(640, 484));
}