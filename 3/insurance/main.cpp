#include <iostream>
#include <string>

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

bool checkByString(std::string insurance)
{
    std::string mainNum = "";
    std::string controlNum = "";
    for (const char& ch: insurance) {
        if (ch == '-' || ch == ' ') {
            continue;
        }

        if ('0' <= ch && ch <= '9') {
            if (mainNum.size() < 9) {
                mainNum += ch;
            } else {
                controlNum += ch;
            }
            continue;
        }

        return false;
    }
    
    if (!(mainNum.size() == 9 && controlNum.size() == 2)) {
        return false;
    }
    return checkInsurance(std::move(mainNum), std::stoull(controlNum));
}

int main() {
    using namespace std;
    std::string insuranceCode;
    getline(cin, insuranceCode);
    cout << checkByString(std::move(insuranceCode)) << '\n';
    return 0;
}
