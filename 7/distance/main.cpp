#include <iostream>

struct Distance {
    int feet;
    double inches;
};

Distance distAddition(const Distance& d1, const Distance& d2) {
    Distance ans;
    ans.feet = d1.feet + d2.feet;
    ans.inches = d1.inches + d2.inches;
    if (ans.inches >= 12.0) {
        ans.inches -= 12.0;
        ++ans.feet;
    }
    return ans;
}
Distance inputDist() {
    Distance d;
    std::cout << "Enter feet: ";
    std::cin >> d.feet;
    std::cout << "Enter inches: ";
    std::cin >> d.inches;
    return d;
}

void printDist(const Distance& d) {
    std::cout << d.feet << "\'-" << d.inches << "\"\n";
}
int main() {
    using namespace std;
    Distance d1 = inputDist();
    Distance d2{1, 5.5};
    printDist(distAddition(d1, d2));

    return 0;   
}
