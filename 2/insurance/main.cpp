#include <iostream>

uint64_t digitSum(uint64_t number)
{
    uint64_t result = 0;
    while (number > 0) {
        result += number % 10;
        number /= 10;
    }
    return result;
}

bool checkInsurance(uint64_t mainNumber, uint64_t controlNumber)
{
    uint64_t sum = digitSum(mainNumber);
    sum %= 101;
    return sum == controlNumber || (sum == 100 && controlNumber == 0);
}

int main() {
    using namespace std;
    uint64_t mainNum, controlNum;
    cin >> mainNum >> controlNum;
    cout << checkInsurance(mainNum, controlNum) << '\n';
    return 0;
}
