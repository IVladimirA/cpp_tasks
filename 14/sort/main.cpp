#include <iostream>

template<typename T>
void sorting (T array[], size_t size) {
    size_t j = 0;
    for (size_t i = 0; i < size; ++i){
        T x = array[i];
        for (j = i - 1; j >= 0 && x < array[j]; --j) {
            array[j + 1] = array[j];
        }
        array[j + 1] = x;
    }
}

template<typename T>
void print(T array[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    using namespace std;
    int arr[] = {9,3,17,6,5,4,31,2,12};
    double arrd[] = {2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2};
    char arrc[] = "Hello, word";
    int cnt1 = sizeof(arr)/sizeof(arr[0]);
    int cnt2 = sizeof(arrd)/sizeof(arrd[0]);
    int cnt3 = sizeof(arrc)/sizeof(arrc[0]) - 1;
    sorting(arr, cnt1);
    print(arr, cnt1);
    sorting(arrd, cnt2);
    print(arrd, cnt2);
    sorting(arrc, cnt3);
    print(arrc, cnt3);
    return 0;
}