#include <iostream>
#include <tuple>
#include <math.h>

std::tuple<int, double, double> findRoots(double a, double b, double c) {
    double D = b * b - 4 * a * c;
    if (D < 0) {
        return {-1, 0, 0};
    }
    if (D == 0) {
        double x;
        x = -b / (2 * a);
        return {0, x, x};
    }
    double x1 = (sqrt(D) - b) / (2 * a);
    double x2 = (-sqrt(D) - b) / (2 * a);
    return {1, x1, x2};
}

int main() {
    using namespace std;
    cout << "Enter a: ";
    double a;
    cin >> a;
    cout << "Enter b: ";
    double b;
    cin >> b;
    cout << "Enter c: ";
    double c;
    cin >> c;
    auto result = findRoots(a, b, c);
    switch(std::get<0>(result)) {
        case -1:
            cout << "No roots :(\n";
            break;
        case 0:
            cout << "Roots are equal x1 = x2 = " << std::get<1>(result) << '\n';
            break;
        case 1:
            cout << "two roots: x1 = " << std::get<1>(result) << ", x2 = " << std::get<2>(result) << '\n';
            break;
        default:
            throw std::logic_error("Invalid findRoots return mode");
    }
    return 0;   
}
