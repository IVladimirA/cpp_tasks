#include <iostream>

int main()
{
    using namespace std;

    cout << "Choose the car of your dream: ";
    char op;
    cin >> op;
    switch(op) {
        case 'V':
            cout << "I want air conditioner\n";
        case 'S':
            cout << "Radio must play\n";
        default:
            cout << "Round wheels\n";
            cout << "Powerful engine\n";
    }
    return 0;
}