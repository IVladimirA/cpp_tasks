#include "student.h"
#include "../../utils/parser/parser.h"

namespace people {

Student::Student(std::string name, std::string lastName, std::string patronymic, std::string phone, Scores scores)
    : Human(name, lastName, patronymic, phone)
    , scores_(scores)
    {}

float Student::averageScore() const {
    return scores_.average();
}

std::string Student::info() const {
    return Human::info() + " " + std::to_string(averageScore());
}

std::string Student::toString(const std::string delimiter) const {
    std::string result = Human::toString(delimiter);
    result += delimiter + scores_.toString(delimiter);
    return result;
}

Student Student::fromString(const std::string value, const std::string delimiter) {
    const auto values = parse(value, delimiter);
    std::string scoreValue = value;
    scoreValue.erase(0, values[0].size() + values[1].size() + values[2].size() + values[3].size() + 4 * delimiter.size());
    return Student(values[0], values[1], values[2], values[3], Scores::fromString(scoreValue, delimiter));
}

}; //namespace people
