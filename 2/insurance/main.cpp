#include <iostream>

uint64_t digitvalue(std::string number)
{
    uint64_t result = 0;
    for (size_t charIdx = 0; charIdx < number.size(); ++charIdx) {
        result += (number.size() - charIdx) * (uint64_t)(number[charIdx] - '0');
    }
    return result;
}

bool checkInsurance(std::string mainNumber, uint64_t controlNumber)
{
    uint64_t digits = digitvalue(mainNumber);
    digits %= 101;
    return digits == controlNumber || (digits == 100 && controlNumber == 0);
}

int main() {
    using namespace std;
    string mainNum;
    uint64_t controlNum;
    cin >> mainNum >> controlNum;
    cout << checkInsurance(mainNum, controlNum) << '\n';
    return 0;
}
