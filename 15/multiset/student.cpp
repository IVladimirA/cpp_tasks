#include "student.h"
#include "id_card.h"

#include <fstream>
#include <iostream>

Student::Student(std::string name, std::string lastName, IdCard* id) : name_(name), lastName_(lastName), iCard(id) {}

void Student::setName(std::string name) {
    name_ = name;
}
void Student::setLastName(std::string lastName) {
    lastName_ = lastName;
}
std::string Student::getName() const {
    return name_;
}
std::string Student::getLastName() const {
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
double Student::getAverageScore() const {
    return averageScore_;
}

void Student::save() const {
    std::ofstream fout("students.txt", std::ios::app);
    fout << getName() << " "
    << getLastName() << " ";
    for (size_t i = 0; i < 5; ++i) {
        fout << scores_[i] <<" ";
    }
    fout << std::endl;
    fout.close();
}

void Student::print() const {
    std::cout << name_ << ' ' << lastName_;
    if (iCard) {
        std::cout << ' ' << iCard->number << ' ' << iCard->category;
    }
    std::cout << '\n';
}

Student::~Student() {
    save();
}

bool operator<(const Student& lhs, const Student& rhs)
{
    if (lhs.name_ == rhs.name_) {
        return lhs.lastName_ < rhs.lastName_;
    }
    return lhs.name_ < rhs.name_;
}
bool operator>(const Student& lhs, const Student& rhs)
{
    return rhs < lhs;
}
bool operator==(const Student& lhs, const Student& rhs)
{
    return lhs.name_ == rhs.name_ && lhs.lastName_ == rhs.lastName_;
}
bool operator!=(const Student& lhs, const Student& rhs)
{
    return !(lhs == rhs);
}