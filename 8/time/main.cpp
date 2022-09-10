#include <iostream>

class Time {
public:
    int hours;
    int minutes;
    int seconds;
    Time() : hours(0), minutes(0), seconds(0) {}
    
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
        normalize();
    }

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

    bool isValid() const {
        return hours >= 0 && minutes >= 0 && seconds >= 0;
    }


};

int main() {
    using namespace std;
    const Time t1;
    const Time t2(12, 45, 0);
    Time t3(14, 30, 15);
    t3.add(t2);

    cout << t1.hours << " " << t1.minutes << " " << t1.seconds << '\n';
    cout << t2.hours << " " << t2.minutes << " " << t2.seconds << '\n';
    cout << t3.hours << " " << t3.minutes << " " << t3.seconds << '\n';
    return 0;   
}
