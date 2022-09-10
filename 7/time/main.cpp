#include <iostream>

struct Time{
    uint64_t hours;
    uint64_t minutes;
    uint64_t seconds;

    void normalize() {
        minutes += seconds / 60;
        seconds %= 60;
        hours += minutes / 60;
        minutes %= 60;
    }

    void add(Time t) {
        hours += t.hours;
        minutes += t.minutes;
        seconds += t.seconds;
        normalize();
    }

    void subtract(Time t) {
        hours -= t.hours;
        minutes -= t.minutes;
        seconds -= t.seconds;
        normalize();
    }

    bool isValid() {
        return hours >= 0 && minutes >= 0 && seconds >= 0;
    }

};

int main()
{
    using namespace std;
    Time t{0, 20, 15};
    t.add({1, 40, 37});
    cout << t.hours << " " << t.minutes << " " << t.seconds << '\n';

    return 0;
}