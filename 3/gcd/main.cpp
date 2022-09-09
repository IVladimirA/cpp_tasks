#include <iostream>

uint64_t gcd(uint64_t a, uint64_t b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int main()
{
    using namespace std;

    cout << "a = ";
    uint64_t a;
    cin >> a;
    cout << "b = ";
    uint64_t b;
    cin >> b;
    cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << '\n';

    return 0;
}
