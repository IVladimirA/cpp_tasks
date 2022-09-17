#include "grades.h"

#include <iostream>

size_t Grades::size() const
{
    return grades_.size();
}

void Grades::setGrade(StudentGrade grade)
{
    grades_[grade.studentName] = grade;
}
void Grades::erase(std::string name)
{
    grades_.erase(name);
}
void Grades::print() const
{
    for (const auto& [name, gradePair]: grades_) {
        std::cout << gradePair.studentName << ' ' << gradePair.grade << '\n';
    }
    std::cout << '\n';
}