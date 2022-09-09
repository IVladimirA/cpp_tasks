#include <iostream>
#include <math.h>
#include <string>

bool input(int& a, int& b) {
    try {
        std::string tmp;
        std::cout << "Enter integer: ";
        std::cin >> tmp;
        a = std::stoi(tmp);
        std::cout << "Enter integer: ";
        std::cin >> tmp;
        b = std::stoi(tmp);
    } catch(...) {
        return false;
    }
    return true;
}

int main() {
    int a, b;
    if (input(a, b)) {
        std::cout << "a + b = " << a + b << '\n';
    } else {
        std::cout << "Incorrect input :(\n";
    }
    return 0;   
}
