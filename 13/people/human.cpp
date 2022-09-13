#include "human.h"

Human::Human(std::string name, std::string lastName, std::string patronymic)
    : name_(name)
    , lastName_(lastName)
    , patronymic_(patronymic)
    {}

std::string Human::fullName() const {
    std::string full = lastName_ + " " + name_;
    if (patronymic_ == "") {
        return full;
    }
    return full + " " + patronymic_;
}

std::string Human::info() const {
    return fullName();
}