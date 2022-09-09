#include <iostream>
#include <math.h>
#include <vector>

struct Point {
    double x;
    double y;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

double traingleSquare(const Point& p1, const Point& p2, const Point& p3) {
    double a = distance(p1, p2);
    double b = distance(p1, p3);
    double c = distance(p2, p3);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

struct Polygon {
    std::vector<Point> nodes;

    double square() const {
        if (nodes.size() < 3) {
            return 0;
        }
        double result = 0;
        for (size_t i = 1; i < nodes.size() - 1; ++i) {
            result += traingleSquare(nodes.front(), nodes[i], nodes[i + 1]);
        }
        return result;
    }
};

int main()
{
    using namespace std;

    Polygon polygon;
    for (size_t i = 0; i < 5; ++i) {
        double x, y;
        cout << "Enter x and y of next polygon node: ";
        cin >> x >> y;
        polygon.nodes.push_back({x, y});
    }
    cout << "Polygon square = " << polygon.square() << '\n';

    return 0;
}
