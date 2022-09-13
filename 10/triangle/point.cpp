#include "point.h"

#include <math.h>

Point::Point() {}

Point::Point(double x, double y) : x(x), y(y) {}

double Point::distance(Point p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}