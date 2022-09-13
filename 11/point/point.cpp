#include "point.h"

#include <math.h>

Point::Point() : x(0.0), y(0.0) {}

Point::Point(double x, double y) : x(x), y(y) {}

double Point::distance(const Point& p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

bool Point::operator<(const Point& p) const {
    return distance({0, 0}) < p.distance({0, 0});
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
    return out << p.x << ' ' << p.y;
}