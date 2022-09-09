#include <iostream>

uint64_t sum(uint64_t n) {
    if (n <= 1) {
        return 5;
    }
    return 5 * n + sum(n - 1);
}

int main()
{
    using namespace std;

    cout << "Enter n: ";
    uint64_t n;
    cin >> n;
    cout << "Sum(n) = " << sum(n) << '\n';

    return 0;
}
