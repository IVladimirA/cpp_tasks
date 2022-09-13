#pragma once

#include "human.h"

#include <vector>

class Student : public Human {
public:
    Student(std::string name, std::string lastName, std::string patronymic, std::vector<int> scores = {});
    float averageScore() const;
private:
    std::vector<int> scores_;
};