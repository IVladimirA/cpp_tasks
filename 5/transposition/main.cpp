#include <iostream>

bool isIn(int* array, size_t n, int x) {
    for (size_t i = 0; i < n; ++i) {
        if (array[i] == x) {
            if (i > 0) {
                std::swap(array[i - 1], array[i]);
            }
            return true;
        }
    }
    return false;
}

int main()
{
    using namespace std;

    cout << "Enter array size: ";
    size_t n;
    cin >> n;
    int* myArray = new int[n];
    for (size_t i = 0; i < n; ++i) {
        cout << "array[" << i << "] = ";
        cin >> myArray[i];
    }
    cout << "Enter query count: ";
    size_t m;
    cin >> m;
    for (size_t i = 0; i < m; ++i) {
        cout << "Enter x: ";
        int x;
        cin >> x;
        if (isIn(myArray, n, x)) {
            cout << "x is in array\n";
            continue;
        }
        cout << "x is not in array\n";
    }

    for (size_t i = 0; i < n; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;
    delete[] myArray;
    return 0;
}