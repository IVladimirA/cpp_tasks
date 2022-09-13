#include <iostream>

template<typename T, typename T1>
class Array {
public:
    Array(int size);
    T sum();
    T1 average();
    void print();
    int add(T);
    ~Array();
private:
    T *data;
    int size;
    int index;
};

template<class T, class T1> Array<T, T1>::Array(int size)
{
    data = new T[size];
    if (data == NULL) {
        std::cerr<< "Error memory ---- exit program" << std::endl;
        exit(1);
    }
    Array::size = size;
    Array::index = 0;
}

template<class T, class T1> T Array<T, T1>::sum()
{
    T sum = 0;
    for (int i = 0; i < index; i++) {
        sum += data[i];
    }
    return(sum);
}
template<class T, class T1> T1 Array<T, T1>::average()
{
    T1 sum = 0;
    for (int i = 0; i < index; i++) {
        sum += data[i];
        }
    return (sum / index);
}

template<class T, class T1> void Array<T, T1>::print()
{
    for (int i = 0; i < index; i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}
template<class T, class T1> int Array<T, T1>::add(T value)
{
    if (index == size) {
        return(-1);
    } else {
        data[index] = value;
        index++;
        return(0);
    }
}

template<class T, class T1> Array<T, T1>::~Array() {
    delete[] data;
}

int main()
{
    using namespace std;
    Array<int, long> numbers(100);
    Array<float, float> values(200);

    size_t i;
    for (i = 0; i < 50; ++i) {
        numbers.add(i);
    }
    numbers.print();
    cout << "Sum = " << numbers.sum () << endl;
    cout << "Average = " << numbers.average() << endl;
    for (i = 0; i < 100; i++) values.add(i * 100);
    values.print();
    cout << "Sum = " << values.sum() << endl;
    cout << "Average = " << values.average() << endl;
    return 0;
}