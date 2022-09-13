#include "time.h"

Time::Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {}

void Time::normalize() {
    if (seconds < 0) {
        seconds += 60;
        --minutes;
    }
    if (minutes < 0) {
        minutes += 60;
        --hours;
    }
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
}


Time operator+(const Time& lht, const Time& rht) {
    Time result(lht.hours + rht.hours, lht.minutes + rht.minutes, lht.seconds + rht.seconds);
    result.normalize();
    return result;
}

Time operator+(const Time& time, int secTime) {
    Time result(time.hours, time.minutes, time.seconds + secTime);
    result.normalize();
    return result;
}
Time operator+(int secTime, const Time& time) {
    return time + secTime;
}
Time operator-(const Time& lht, const Time& rht) {
    Time result(lht.hours - rht.hours, lht.minutes - rht.minutes, lht.seconds - rht.seconds);
    result.normalize();
    return result;
}

std::ostream& operator<<(std::ostream& out, const Time& time) {
    return out << time.hours << ':' << time.minutes << ':' << time.seconds;
}