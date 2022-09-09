#include <iostream>
#include <string>

void greeting(std::string);

int main()
{
    using namespace std;

    cout << "Enter your name: ";
    string name;
    cin >> name;


    return 0;
}

void greeting(const std::string& name) {
    std::cout << name << ", hello!\n";
}
