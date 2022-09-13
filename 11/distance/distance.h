#pragma once

#include <iostream>

class Distance {
private:
    const float MTF;
public:
    int feet;
    double inches;

    Distance();
    Distance(float meters);
    Distance(int feet, double inches);
    void input();
    void print() const;
    Distance operator+(const Distance& dist) const;
    Distance operator+(float meters) const;
    operator float() const;
    Distance& operator=(const Distance& dist);
    friend Distance operator-(const Distance& lhd, const Distance& rhd);
    friend std::ostream& operator<<(std::ostream& out, const Distance& dist);
};

Distance operator+(float meters, const Distance& dist);