#include "triangle.h"

#include <iostream>

int main() {
    using namespace std;
    Point p1(0, 0);
    Point p2(0, 1);
    Point p3(1, 0);
    TriangleWithPtrs triangle1(&p1, &p2, &p3);
    cout << "Triangle square: " << triangle1.square() << ", perimeter: " << triangle1.perimeter() << '\n';
    TriangleWithVals triangle2(0, 0, 0, 1, 1, 0);
    cout << "Triangle square: " << triangle2.square() << ", perimeter: " << triangle2.perimeter() << '\n';
    return 0;
}
