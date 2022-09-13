#pragma once

#include "point.h"

struct TriangleEdges {
    double a;
    double b;
    double c;

    double perimeter() const {
        return a + b + c;
    }
};


class TriangleWithPtrs {
public:
    Point* p1;
    Point* p2;
    Point* p3;
    TriangleWithPtrs(Point* p1, Point* p2, Point* p3);
    TriangleEdges edges() const;
    double square() const;
    double perimeter() const;
};

class TriangleWithVals {
public:
    Point p1;
    Point p2;
    Point p3;
    TriangleWithVals(double ax, double ay, double bx, double by, double cx, double cy);
    TriangleEdges edges() const;
    double square() const;
    double perimeter() const;
};