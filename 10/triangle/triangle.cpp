#include "triangle.h"

#include <math.h>

TriangleWithPtrs::TriangleWithPtrs(Point* p1, Point* p2, Point* p3) : p1(p1), p2(p2), p3(p3) {}

TriangleEdges TriangleWithPtrs::edges() const {
    return {p1->distance(*p2), p2->distance(*p3), p3->distance(*p1)};
}

double TriangleWithPtrs::square() const {
    const auto sides = edges();
    const double p = sides.perimeter() / 2;
    return sqrt(p * (p - sides.a) * (p - sides.b) * (p - sides.c));
}
double TriangleWithPtrs::perimeter() const {
    return edges().perimeter();
}

TriangleWithVals::TriangleWithVals(double ax, double ay, double bx, double by, double cx, double cy) : p1(ax, ay), p2(bx, by), p3(cx, cy) {}

TriangleEdges TriangleWithVals::edges() const {
    return {p1.distance(p2), p2.distance(p3), p3.distance(p1)};
}

double TriangleWithVals::square() const {
    const auto sides = edges();
    const double p = sides.perimeter() / 2;
    return sqrt(p * (p - sides.a) * (p - sides.b) * (p - sides.c));
}
double TriangleWithVals::perimeter() const {
    return edges().perimeter();
}