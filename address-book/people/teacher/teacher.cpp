#include "teacher.h"
#include "../../utils/parser/parser.h"

namespace people {

Teacher::Teacher(std::string name, std::string lastName, std::string patronymic, Subject subject)
    : Human(name, lastName, patronymic)
    , subject_(subject)
    {}

std::string Teacher::info() const {
    return Human::info() + " " + subject_.info();
}

std::string Teacher::toString(const std::string delimiter) const {
    std::string result = Human::toString(delimiter);
    result += delimiter + subject_.toString(delimiter);
    return result;
}

Teacher Teacher::fromString(const std::string value, const std::string delimiter) {
    const auto values = parse(value, delimiter);
    std::string scoreValue = value;
    scoreValue.erase(0, values[0].size() + values[1].size() + values[2].size() + 3 * delimiter.size());
    return Teacher(values[0], values[1], values[2], Subject::fromString(scoreValue, delimiter));
}

}; //namespace people
