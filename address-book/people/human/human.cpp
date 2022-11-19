#include "human.h"
#include "../../utils/parser/parser.h"

namespace people {

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

std::string Human::toString(const std::string delimiter) const {
    std::string full = name_ + delimiter + lastName_;
    if (patronymic_ == "") {
        return full;
    }
    return full + delimiter + patronymic_;
}

Human Human::fromString(const std::string value, const std::string delimiter) {
    const auto values = parse(value, delimiter);
    return Human(values[0], values[1], values[2]);
}

}; //namespace people
