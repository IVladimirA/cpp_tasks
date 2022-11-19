#pragma once

#include "../human/human.h"
#include "../../scores/scores.h"

namespace people {

class Student : public Human {
public:
    Student(std::string name, std::string lastName, std::string patronymic, Scores scores);
    float averageScore() const;
    std::string info() const;
    std::string toString(const std::string delimiter = ";") const;
    static Student fromString(const std::string value, const std::string delimiter = ";");
private:
    Scores scores_;
};

}; //namespace people
