#include <iostream>

int main() {
    using namespace std;

    size_t n;
    cout << "Enter array size: ";
    cin >> n;
    int* myArray = new int[n];
    for (size_t i = 0; i < n; ++i) {
        cout << "array[" << i << "] = ";
        cin >> myArray[i];
    }
    for (size_t i = 0; i < n; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < n; ++j) {
            minIdx = (myArray[j] < myArray[minIdx]) ? j : minIdx;
        }
        if (i != minIdx) {
            std::swap(myArray[i], myArray[minIdx]);
        }
    }
    for (size_t i = 0; i < n; ++i) {
        cout << myArray[i] << '\t';
    }
    cout << '\n';

    delete[] myArray;
    return 0;   
}
