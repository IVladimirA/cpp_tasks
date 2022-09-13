#include "teacher.h"

Teacher::Teacher(std::string name, std::string lastName, std::string patronymic, int workHours)
    : Human(name, lastName, patronymic)
    , workHours_(workHours)
    {}

int Teacher::workHours() const {
    return workHours_;
}

std::string Teacher::info() const {
    return Human::info() + " " + std::to_string(workHours());
}