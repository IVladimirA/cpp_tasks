#pragma once

#include "human.h"
#include <string>

class Teacher : public Human {
public:
    Teacher(std::string name, std::string lastName, std::string patronymic, int workHours = 0);
    int workHours() const;
    std::string info() const;
private:
    int workHours_;
};