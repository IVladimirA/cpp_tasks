#include <iostream>

class Time {
public:
    int hours;
    int minutes;
    int seconds;
    Time() : hours(0), minutes(0), seconds(0) {}
    
    class ExNegative {
    public:
        std::string message() const {
            return "negative time value";
        }
    };

    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
        if (!isValid()) {
            throw ExNegative();
        }
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
        if (!isValid()) {
            throw ExNegative();
        }
        normalize();
    }

    void subtract(Time t) {
        hours -= t.hours;
        minutes -= t.minutes;
        seconds -= t.seconds;
        if (!isValid()) {
            throw ExNegative();
        }
        normalize();
    }

    bool isValid() const {
        return hours >= 0 && minutes >= 0 && seconds >= 0;
    }


};

int main() {
    using namespace std;
    Time t1(15, 45, 0);
    Time t2(14, 30, 15);
    t1.add(t2);
    cout << "Succesful addition\n";
    t2.subtract(t1);
    cout << "Succesful subtraction\n";
    return 0;   
}
