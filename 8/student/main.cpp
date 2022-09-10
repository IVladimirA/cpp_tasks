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
    student->setScores(scores);
    student->setAverageScore(sum / 5.0);
    cout << "Average score for " << student->getName() << " " << student->getLastName() << " is " << student->getAverageScore() << '\n';
    delete student;
    return 0;   
}
