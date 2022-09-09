#include <iostream>

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 2, b = 5;
    std::cout << a << " " << b << '\n';
    swap(a, b);
    std::cout << a << " " << b << '\n';
    swap(&a, &b);
    std::cout << a << " " << b << '\n';
    return 0;   
}
