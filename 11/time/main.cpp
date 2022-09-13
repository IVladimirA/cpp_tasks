#include "time.h"

#include <iostream>

int main() {
    using namespace std;
    
    Time t1(12, 15, 40);
    Time t2(17, 20, 05);
    cout << "t1: " << t1 << "\nt2: " << t2 << '\n';
    cout << "t1 + t2: " << t1 + t2 << '\n';
    cout << "t2 - t1: " << t2 - t1 << '\n';
    cout << "t1 + 115: " << t1 + 115 << '\n';
    cout << "115 + t1: " << 115 + t1 << '\n';
    return 0;   
}
