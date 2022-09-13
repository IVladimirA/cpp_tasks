#pragma once

#include <iostream>

class Point {
public:
    double x;
    double y;
    Point();
    Point(double x, double y);
    double distance(const Point& p) const;
    bool operator<(const Point& p) const;
};

std::ostream& operator<<(std::ostream& out, const Point& p);