#include "creators.h"

#include <iostream>
#include <vector>

namespace creators {

Scores scores() {
    using namespace std;
    cout << "-- Scores --\n"
         << "Score count: ";
    size_t count;
    cin >> count;
    std::vector<int> values;
    for (size_t scoreIdx = 0; scoreIdx < count; ++scoreIdx) {
        cout << "Next score: ";
        int score;
        cin >> score;
        values.push_back(score);
    }
    return Scores(values);
}

Subject subject() {
    using namespace std;
    cout << "-- Subject --\n"
         << "Name: ";
    string name;
    cin >> name;
    cout << "Hours: ";
    int hours;
    cin >> hours;
    return Subject(name, hours);
}

people::Student student() {
    using namespace std;
    cout << "-- Student --\n"
         << "Name: ";
    string name;
    cin >> name;
    cout << "Last name: ";
    string lastName;
    cin >> lastName;
    cout << "Patronymic: ";
    string patronymic;
    cin >> patronymic;
    cout << "Phone number: ";
    string phone;
    cin >> phone;
    return people::Student(name, lastName, patronymic, phone, scores());
}

people::Teacher teacher() {
    using namespace std;
    cout << "-- Teacher --\n"
         << "Name: ";
    string name;
    cin >> name;
    cout << "Last name: ";
    string lastName;
    cin >> lastName;
    cout << "Patronymic: ";
    string patronymic;
    cin >> patronymic;
    cout << "Phone number: ";
    string phone;
    cin >> phone;
    return people::Teacher(name, lastName, patronymic, phone, subject());
}

}; // namespace creators
