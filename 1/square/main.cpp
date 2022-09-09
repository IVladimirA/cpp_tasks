#include <cmath>
#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
};

double traingleSquareHeron(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double polygonSquareGauss(const std::vector<Point>& nodes) {
    double a = 0;
    double b = 0;
    for (size_t i = 0; i < nodes.size() - 1; ++i) {
        a += nodes[i].x * nodes[i + 1].y;
        b += nodes[i + 1].x * nodes[i].y;
    }
    return std::abs(a + nodes.back().x * nodes[0].y - b - nodes[0].x * nodes.back().y) / 2;    
}

int main()
{
    using namespace std;

    cout << "Enter triangle edges length: ";
    double a, b, c;
    cin >> a >> b >> c;
    cout << "Triangle square: " << traingleSquareHeron(a, b, c) << "\n";
    cout << "Enter polygon nodes count: ";
    size_t n;
    cin >> n;
    cout << "Enter polygon nodes coordinates: ";
    std::vector<Point> nodes;
    for (size_t i = 0; i < n; ++i) {
        Point p;
        cin >> p.x >> p.y;
        nodes.push_back(p);
    }
    cout << "Polygon square: " << polygonSquareGauss(nodes) << "\n";
    return 0;
}