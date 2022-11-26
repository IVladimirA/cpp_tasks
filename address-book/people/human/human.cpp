#include "human.h"
#include "../../utils/parser/parser.h"

namespace people {

Human::Human(std::string name, std::string lastName, std::string patronymic, std::string phone)
    : name_(name)
    , lastName_(lastName)
    , patronymic_(patronymic)
    , phoneNumber_(phone)
    {}

std::string Human::fullName() const {
    return lastName_ + " " + name_ + " " + patronymic_;
}

std::string Human::info() const {
    if (phoneNumber_ != "") {
        return fullName() + " " + phoneNumber_;
    }
    return fullName();
}

std::string Human::toString(const std::string delimiter) const {
    std::string full = name_ + delimiter + lastName_ + delimiter + patronymic_;
    if (phoneNumber_ == "") {
        return full;
    }
    return full + delimiter + phoneNumber_;
}

Human Human::fromString(const std::string value, const std::string delimiter) {
    const auto values = parse(value, delimiter);
    return Human(values[0], values[1], values[2], values[3]);
}

}; //namespace people
