#include <cstring>
#include <iostream>


int main(int argc, char** argv) {
    if (argc < 4) {
        std::cout << "Not enough arguments: " << argc - 1 << " instead of 3\n";
        return 0;
    }
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    if (strncmp(argv[1], "-a", 2) == 0) {
        std::cout << a << " + " << b << " = " << a + b << '\n';
    } else if (strncmp(argv[1], "-m", 2) == 0) {
        std::cout << a << " * " << b << " = " << a * b << '\n';
    } else {
        std::cout << "Incorrect operation type: " << argv[1] << " insted of -a or -m\n";
    }
    return 0;
}
