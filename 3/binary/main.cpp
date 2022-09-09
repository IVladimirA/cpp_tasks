#include <iostream>
#include <string>

std::string binaryForm(uint64_t n) {
    if (n < 1) {
        return "";
    }
    return binaryForm(n / 2) + std::to_string(n % 2);
}

int main()
{
    using namespace std;

    cout << "Enter n: ";
    uint64_t n;
    cin >> n;
    cout << "Binary form of " << n << " = " << binaryForm(n) << '\n';

    return 0;
}
