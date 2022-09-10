#include <iostream>
#include <optional>

int sum(int* array, size_t n) {
    int result = 0;
    for (size_t i = 0; i < n; ++i) {
        result += array[i];
    }
    return result;
}

int sumPositive(int* array, size_t n) {
    int result = 0;
    for (size_t i = 0; i < n; ++i) {
        if (array[i] > 0)
        result += array[i];
    }
    return result;
}

int sumNegative(int* array, size_t n) {
    return sum(array, n) - sumPositive(array, n);
}

int sumOddIdx(int* array, size_t n) {
    int result = 0;
    for (size_t i = 0; i < n; i += 2) {
        result += array[i];
    }
    return result;
}

int sumEvenIdx(int* array, size_t n) {
    return sum(array, n) - sumOddIdx(array, n);
}

double avg(int* array, size_t n) {
    return (double)(sum(array, n)) / n;
}

size_t maxIdx(int* array, size_t n) {
    std::optional<size_t> idx;
    std::optional<int> max;
    for (size_t i = 0; i < n; ++i) {
        if (!max || (max && array[i] > *max)) {
            max = array[i];
            idx = i;
        }
    }
    if (idx) {
        return *idx;
    }
    return -1;
}

size_t minIdx(int* array, size_t n) {
    std::optional<size_t> idx;
    std::optional<int> min;
    for (size_t i = 0; i < n; ++i) {
        if (!min || (min && array[i] < *min)) {
            min = array[i];
            idx = i;
        }
    }
    if (idx) {
        return *idx;
    }
    return -1;
}

int production(int* array, size_t n, size_t leftIdx, size_t rightIdx) {
    int result = 1;
    for (size_t i = leftIdx; i <= rightIdx; ++i) {
        result *= array[i];
    }
    return result;
}

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

    cout << "Sum = " << sum(myArray, n) << '\n';
    cout << "Average = " << avg(myArray, n) << '\n';
    cout << "Sum of positive = " << sumPositive(myArray, n) << '\n';
    cout << "Sum of negative = " << sumNegative(myArray, n) << '\n';
    cout << "Sum of odd idexed = " << sumOddIdx(myArray, n) << '\n';
    cout << "Sum of even indexed = " << sumEvenIdx(myArray, n) << '\n';
    cout << "Max = " << myArray[maxIdx(myArray, n)] << '\n';
    cout << "Min = " << myArray[minIdx(myArray, n)] << '\n';
    size_t left = min(minIdx(myArray, n), maxIdx(myArray, n));
    size_t right = max(minIdx(myArray, n), maxIdx(myArray, n));
    cout << "Production = " << production(myArray, n, left, right) << '\n';
    delete[] myArray;
    return 0;   
}
