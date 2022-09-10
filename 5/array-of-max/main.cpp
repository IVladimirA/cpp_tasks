#include <iostream>

// caller takes ownership of created array
int* arrayOfMax(int* arr1, int* arr2, const size_t n) {
    int* result = new int[n];
    for (size_t i = 0; i < n; ++i) {
        result[i] = std::max(arr1[i], arr2[i]);
    }
    return result;
}

int main()
{
    using namespace std;

    int a[]={1,2,3,4,5,6,7,2};
    int b[]={7,6,5,4,3,2,1,3};
    size_t n = sizeof(a)/sizeof(a[0]);
    int* c = arrayOfMax(a, b, n);
    for (size_t i = 0; i < n; ++i) {
        cout << c[i] << " ";
    }
    cout << endl;
    delete []c;
    return 0;
}