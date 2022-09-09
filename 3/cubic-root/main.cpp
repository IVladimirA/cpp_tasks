#include <iostream>
#include <math.h>

double cubicRootStd(double a) {
    return pow(a, 1.0/3);
}

double cubicRoot(double a) {
    double last = a;
    double current = (a / pow(last, 2) + 2 * last) / 3;
    while (abs(last - current) >= 1e-5) {
        last = current;
        current = (a / pow(last, 2) + 2 * last) / 3;
    }
    return current;
}

int main()
{
    using namespace std;

    cout << "Enter number: ";
    double a;
    cin >> a;
    cout << "pow() root: " << cubicRootStd(a) << '\n';
    cout << "Iteration formula root: " << cubicRoot(a) << '\n';

    return 0;
}
