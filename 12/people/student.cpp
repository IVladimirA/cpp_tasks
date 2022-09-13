#include "student.h"

Student::Student(std::string name, std::string lastName, std::string patronymic, std::vector<int> scores)
    : Human(name, lastName, patronymic)
    , scores_(scores)
    {}

float Student::averageScore() const {
    int scoreSum = 0;
    for (int score: scores_) {
        scoreSum += score;
    }
    return (float)scoreSum / (float)scores_.size();
}