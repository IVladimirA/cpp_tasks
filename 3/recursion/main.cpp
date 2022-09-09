#include <iostream>

uint64_t sum(uint64_t n) {
    if (n == 1) {
        return 1;
    }
    return n + sum(n - 1);
}

int main()
{
    using namespace std;

    cout << "n = ";
    uint64_t n;
    cin >> n;
    cout << "Sum of 1.." << n << " is " << sum(n) << '\n';

    return 0;
}
