#include <iostream>
#include <fstream>

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
    fstream out ("array.txt", ios::out);
    if (!out) {
        cout << "Could not open file array.txt\n";
        return 1;
    }
    out << "Array:\n";
    for (size_t i = 0; i < n; ++i) {
        out << myArray[i] << ' ';
    }
    out << '\n';
    for (size_t i = 0; i < n; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < n; ++j) {
            minIdx = (myArray[j] < myArray[minIdx]) ? j : minIdx;
        }
        if (i != minIdx) {
            std::swap(myArray[i], myArray[minIdx]);
        }
    }
    
    out << "After sorting:\n";
    for (size_t i = 0; i < n; ++i) {
        out << myArray[i] << ' ';
    }
    out << '\n';
    out.close();
    delete[] myArray;
    return 0;   
}
