#include <iostream>

template<typename T, typename returnT>
returnT average(const T* array, size_t n) {
    returnT sum = 0;
    for (size_t i = 0; i < n; ++i) {
        sum += array[i];
    }
    return sum / n;
}


int main()
{
    using namespace std;
    int integers[2] = {1, 2};
    long numbers[2] = {1, 2};
    double doubles[2] = {1.1, 2.2};
    char chars[3] = {'a', 'b', 'c'};
    cout << "int: " << average<int, double>(integers, 2) << '\n';
    cout << "long: " << average<long, double>(numbers, 2) << '\n';
    cout << "double: " << average<double, double>(doubles, 2) << '\n';
    cout << "char: " << average<char, char>(chars, 2) << '\n';
    return 0;
}