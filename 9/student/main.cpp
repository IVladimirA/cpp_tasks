#include "student.h"

#include <iostream>

int main() {
    using namespace std;
    Student* student = new Student("Vladimir", "Ivanov");
    int scores[5];
    int sum = 0;
    for (size_t i = 0; i < 5; ++i) {
        cout << "Score " << i + 1 << ": ";
        cin >> scores[i];
        sum += scores[i];
    }
    try {
    student->setScores(scores);
    } catch(Student::ExScore& ex) {
        cout << "Initialization error " << ex.origin << '\n';
        cout << "Inputted score value " << ex.iValue << " is forbidden\n";
    }
    student->setAverageScore(sum / 5.0);
    cout << "Average score for " << student->getName() << " " << student->getLastName() << " is " << student->getAverageScore() << '\n';
    delete student;
    return 0;   
}
