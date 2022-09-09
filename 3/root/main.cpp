#include <cmath>
#include <iostream>

double root(double a, int dergee) {
    double left = 0;
    double right = a;
    while (right - left > 1e-10) {
        double middle = (left + right) / 2;
        if (std::pow(middle, dergee) < a) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return right;
}

int main()
{
    using namespace std;

    cout << "a = ";
    double a;
    cin >> a;
    cout << "Root degree = ";
    int degree;
    cin >> degree;
    cout << "Root of degree " << degree << " from " << a << " is " << root(a, degree) << '\n';

    return 0;
}
