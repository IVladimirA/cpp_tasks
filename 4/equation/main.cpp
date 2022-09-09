#include <iostream>
#include <math.h>

int findRoots(double a, double b, double c, double& x1, double& x2) {
    double D = b * b - 4 * a * c;
    if (D < 0) {
        return -1;
    }
    if (D == 0) {
        x1 = -b / (2 * a);
        x2 = x1;
        return 0;
    }
    x1 = (sqrt(D) - b) / (2 * a);
    x2 = (-sqrt(D) - b) / (2 * a);
    return 1;
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
    double x1, x2;
    const int resultMode = findRoots(a, b, c, x1, x2);
    switch(resultMode) {
        case -1:
            cout << "No roots :(\n";
            break;
        case 0:
            cout << "Roots are equal x1 = x2 = " << x1 << '\n';
            break;
        case 1:
            cout << "two roots: x1 = " << x1 << ", x2 = " << x2 << '\n';
            break;
        default:
            throw std::logic_error("Invalid findRoots return mode");
    }
    return 0;   
}
