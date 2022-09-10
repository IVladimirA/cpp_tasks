#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using Tuple = std::tuple<std::string, int, double>;

void printTupleOfThree(const Tuple& t) {
    std::cout << "("
    << std::get<0>(t) << ", "
    << std::get<1>(t) << ", "
    << std::get<2>(t) << ")" << std::endl;
}

Tuple funtup(std::string s, int a, double d)
{
    s.append("!");
    return std::make_tuple(s, a, d * 10);
}

Tuple clear(Tuple t)
{
    std::get<0>(t).clear();
    std::get<1>(t) = 0;
    std::get<2>(t) = 0.0;
    return t;
}

int main()
{
    using namespace std;

    vector<string> v1{"one", "two", "three", "four", "five", "six"};
    vector<int> v2 = {1, 2, 3, 4, 5, 6};
    vector<double> v3 = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    auto t0 = make_tuple(v1[0], v2[0], v3[0]);
    printTupleOfThree(t0);
    auto t1 = funtup(v1[1], v2[1], v3[1]);
    printTupleOfThree(t1);
    printTupleOfThree(clear(t1));
    return 0;
}