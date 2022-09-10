#include "student.h"

#include <fstream>

Student::Student(std::string name, std::string lastName) : name_(name), lastName_(lastName) {}

void Student::setName(std::string name) {
    name_ = name;
}
void Student::setLastName(std::string lastName) {
    lastName_ = lastName;
}
std::string Student::getName() {
    return name_;
}
std::string Student::getLastName() {
    return lastName_;
}
void Student::setScores(int scores[]) {
    for (size_t i = 0; i < 5; ++i) {
        scores_[i] = scores[i];
    }
}
void Student::setAverageScore(double score) {
    averageScore_ = score;
}
double Student::getAverageScore() {
    return averageScore_;
}

void Student::save() {
    std::ofstream fout("students.txt", std::ios::app);
    fout << getName() << " "
    << getLastName() << " ";
    for (size_t i = 0; i < 5; ++i) {
        fout << scores_[i] <<" ";
    }
    fout << std::endl;
    fout.close();
}

Student::~Student() {
    save();
}