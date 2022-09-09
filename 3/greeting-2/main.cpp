#include <iostream>
#include <string>

std::string greeting(std::string);

int main()
{
    using namespace std;

    cout << "Enter your name: ";
    string name;
    cin >> name;
    cout << greeting(name);

    return 0;
}

std::string greeting(std::string name) {
    return name + ", hello!\n";
}
