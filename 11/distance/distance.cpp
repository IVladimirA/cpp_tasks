#include "distance.h"

Distance::Distance() : feet(0), inches(0.0), MTF(3.280833F) {}

Distance::Distance(float meters) : MTF(3.280833F)
{
    float fltfeet = MTF * meters;
    feet = int (fltfeet);
    inches = 12 * (fltfeet - feet);
}

Distance::Distance(int feet, double inches) : feet(feet), inches(inches), MTF(3.280833F) {}

void Distance::input() {
    std::cout << "Feet: ";
    std::cin >> feet;
    std::cout << "Inches: ";
    std::cin >> inches;
}

void Distance::print() const {
    std::cout << feet << "\'-" << inches << "\"\n";
}

Distance Distance::operator+(const Distance& dist) const {
    Distance result(feet + dist.feet, inches + dist.inches);
    if (result.inches >= 12.0) {
        ++result.feet;
        result.inches -= 12.0;
    }
    return result;
}

Distance Distance::operator+(float meters) const {
    return *this + Distance(meters);
}

Distance operator+(float meters, const Distance& dist) {
    return dist + meters;
}

Distance::operator float() const {
    float fracfeet = inches / 12;
    fracfeet += static_cast<float>(feet);
    return fracfeet / MTF;
}

Distance& Distance::operator=(const Distance& dist) {
    feet = dist.feet;
    inches = dist.inches;
    return *this;
}

Distance operator-(const Distance& lhd, const Distance& rhd) {
    Distance result(lhd.feet - rhd.feet, lhd.inches - rhd.inches);
    if (result.inches < 0.0) {
        result.inches += 12.0;
        --result.feet;
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const Distance& dist)
{
    out << dist.feet << "\'-" << dist.inches << "\"\n";
    return out;
}