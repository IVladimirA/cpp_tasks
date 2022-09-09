#include <iostream>

int main()
{
    using namespace std;

    cout << "Enter your name\n";
    cout << "Enter a and b: ";
    double a, b;
    string name;
    cin >> a >> name >> b;
    cout << "Name " << name;
    double dblResult = a / b;
    int intResult = a / b;
    cout << "intResult size: " << sizeof(intResult) << "\ndblResult size: " << sizeof(dblResult) << "\na / b size: " << sizeof(a / b) << endl;
    cout << "intResult = " << intResult << endl; // integer type truncates devision result
    cout << "dblResult = " << dblResult << endl;
    cout.precision(3);
    cout << "dblResult with precision 3: " << dblResult << endl;
    return 0;
}

// TODO cin part