#include <iostream>

int main()
{
    using namespace std;

    cout << "Enter point coordsinates: ";
    double x, y;
    cin >> x >> y;
    if (x * x + y * y < 9 && y > 0) {
        cout << "Inside\n";
    } else if (x * x + y * y > 9 || y < 0) {
        cout << "Outside\n";
    } else {
        cout << "On border\n";
    }
    return 0;
}