#include <iostream>

int main()
{
    using namespace std;

    cout << "Enter 3 numbers\n";
    double a, b, c;
    cin >> a >> b >> c;
    cout << "Maximum of " << a << ", " << b << ", " << c<<  " is " << max(a, max(b, c)) << '\n';

    return 0;
}