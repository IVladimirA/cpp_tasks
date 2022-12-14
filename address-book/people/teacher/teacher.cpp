#include "teacher.h"
#include "../../utils/parser/parser.h"

#include <stdexcept>

namespace people {

Teacher::Teacher(std::string name, std::string lastName, std::string patronymic, std::string phone, Subject subject)
    : Human(name, lastName, patronymic, phone)
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

Teacher Teacher::fromString(std::string value, const std::string delimiter) {
    const auto values = parse(value, delimiter);
    if (values.size() < 5) {
        throw std::invalid_argument("Not enough values to parse Teacher from \"" + value + '\"');
    }
    value.erase(0, values[0].size() + values[1].size() + values[2].size() + values[3].size() + 4 * delimiter.size());
    return Teacher(values[0], values[1], values[2], values[3], Subject::fromString(value, delimiter));
}

}; //namespace people
