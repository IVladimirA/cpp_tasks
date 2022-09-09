#include <iostream>
#include <math.h>

int main()
{
    using namespace std;

    double x1, x2;
    cout << "x1 = ";
    cin >> x1;
    cout << "x2 = ";
    cin >> x2;
    cout << "\tx\tsin(x)\n";
    do {
        cout << '\t' << x1 << '\t' << sin(x1) << '\n';
        x1 += 0.01;
    } while (x1 <= x2);
    return 0;
}