#include <cmath>
#include <iostream>

double triangleSquare(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double triangleSquare(double a) {
    return triangleSquare(a, a, a);
}

int main()
{
    using namespace std;

    cout << "Enter a, b, c: ";
    double a;
    cin >> a;
    double b;
    cin >> b;
    double c;
    cin >> c;
    cout << "Square (a, b, c): " << triangleSquare(a, b, c) << '\n';
    cout << "Square (a, a, a): " << triangleSquare(a, a, a) << '\n';
    cout << "Square (a): " << triangleSquare(a) << '\n';

    return 0;
}
