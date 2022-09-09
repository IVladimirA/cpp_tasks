#include <iostream>
#include <string>

void greeting(const std::string& name) {
    std::cout << name << ", hello!\n";
}

void greeting(const std::string& name, int k) {
    std::cout << name << ", hello! your input " << k << '\n';
}

int main()
{
    using namespace std;

    cout << "Enter your name: ";
    string name;
    cin >> name;
    cout << "Enter number: ";
    int k;
    cin >> k;
    greeting(name);
    greeting(name, k);

    return 0;
}