#include <iostream>

void printArray(const int Arr[], const size_t N)
{
    for (size_t i = 0; i < N; ++i) {
        std::cout << Arr[i] <<" ";
    }
    std::cout << "\n";
}

bool ascendingComp(const int a, const int b)
{
    return a < b;
}

bool descendingComp(const int a, const int b)
{
    return a > b;
}

void bubble_sort(int Arr[], const size_t N, bool (*compare)(int a,int b))
{
    for (size_t i = 1; i < N; ++i) {
        for (size_t j = 0; j < N - 1; ++j) {
            if (!(*compare)(Arr[j], Arr[j + 1])) {
                std::swap(Arr[j], Arr[j + 1]);
            }
        }
    }
}

int main()
{
    using namespace std;

    size_t n;
    cout << "Enter array size: ";
    cin >> n;
    int* myArray = new int[n];
    for (size_t i = 0; i < n; ++i) {
        cout << "array[" << i << "] = ";
        cin >> myArray[i];
    }
    cout << "1. Ascending order\n";
    cout << "2. Descending order\n";
    int sortMode;
    cin >> sortMode;
    cout << "Initial array: ";
    printArray(myArray, n);
    bool (*orderComp[2])(int, int) = {ascendingComp, descendingComp};
    bubble_sort(myArray, n, orderComp[sortMode - 1]);
    printArray(myArray, n);
    delete[] myArray;
    return 0;
}