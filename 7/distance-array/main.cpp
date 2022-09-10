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
    
    cout << "Enter array size: ";
    size_t n;
    cin >> n;
    Distance* distances = new Distance[n];
    for (size_t i = 0; i < n; ++i) {
        distances[i] = inputDist();
    }
    Distance sum{0, 0};
    for (size_t i = 0; i < n; ++i) {
        printDist(distances[i]);
        sum = distAddition(sum, distances[i]);
    }
    printDist(sum);
    delete[] distances;

    return 0;   
}
