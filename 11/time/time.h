#pragma once

#include <iostream>

class Time {
public:
    int hours;
    int minutes;
    int seconds;
    Time(int hours = 0, int minutes = 0, int seconds = 0);
    void normalize();
};

std::ostream& operator<<(std::ostream& out, const Time& time);
Time operator+(const Time& lht, const Time& rht);
Time operator+(const Time& time, int secTime);
Time operator+(int secTime, const Time& time);
Time operator-(const Time& lht, const Time& rht);
