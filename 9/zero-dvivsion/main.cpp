#include <iostream>
#include <string>

class DivideByZeroError {
public:
    DivideByZeroError() : message("Division by zero") {}
    void printMessage() const {
        std::cout << message << '\n';
    }
private:
    std::string message;
};

float quotient(int numl, int num2)
{
    if (num2 == 0)
        throw DivideByZeroError();
    return (float)numl / num2;
}

int main() {
    using namespace std;

    cout << "Enter number: ";
    int number;
    cin >> number;

    for (int i = -10; i < 10; i++) {
        try {
            float result = quotient(number, i);
            cout << "quotient = " << result << endl;
        } catch (DivideByZeroError& error) {
            cout << "Error: ";
            error.printMessage();
        }
    }
    return 0;   
}
