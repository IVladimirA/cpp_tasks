#include "distance.h"

#include <iostream>

int main() {
    using namespace std;

    Distance d1, d2, d3, d4, d5, d6;
    d1.input();
    d2.input();
    d3 = d1 + d2;
    d3.print();
    cout << d3;
    d4 = d1 + d2 + d3;
    d4.print();
    cout << d4;
    cout << d4 - d3;
    d5 = 2.35F;
    d6 = d5;
    float meters = static_cast<float>(d5);
    cout << d5;
    cout << "Meters = " << meters << '\n';
    cout << "(float)dist = " << (float)d6 << '\n';
    cout << "Distance + float - " << d5 + 1.2F;
    cout << "float + Distance - " << 1.2F + d5;
    return 0;   
}
