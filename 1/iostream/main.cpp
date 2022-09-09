#include <iostream>
#include <string>

int main()
{
    using namespace std;

    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello, " << name << "!\n";
    return 0;
}