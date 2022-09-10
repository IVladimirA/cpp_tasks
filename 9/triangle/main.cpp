#include <cmath>
#include <iostream>

class Triangle {
public:
    double a;
    double b;
    double c;
    Triangle() : a(1), b(1), c(1) {}
    Triangle(double first, double second, double third) : a(first), b(second), c(third) {
        if (a > b + c || b > a + c || c > a + b) {
            throw std::invalid_argument("One side of triangle bigger than sum of other two");
        }
    }
    double square() const {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main()
{
    using namespace std;

    cout << "Enter triangle edges length: ";
    double a, b, c;
    cin >> a >> b >> c;
    const Triangle t(a, b, c);
    cout << "square = " << t.square() << '\n';
    return 0;
}