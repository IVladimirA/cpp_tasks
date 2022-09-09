#include <iostream>

int gcd(int a, int b) {
    while (a != 0) {
        b %= a;
        std::swap(a, b);
    }
    return b;
}

int main()
{
    using namespace std;

    int a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "gcd(a, b) = " << gcd(a, b) << '\n';
    return 0;
}