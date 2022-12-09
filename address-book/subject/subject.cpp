#include "subject.h"
#include "../utils/parser/parser.h"

#include <stdexcept>

Subject::Subject(std::string name, int hours)
    : name_(name)
    , hours_(hours)
    {}

std::string Subject::info() const {
    return name_ + " " + std::to_string(hours_);
}

std::string Subject::toString(const std::string delimiter) const {
    return name_ + delimiter + std::to_string(hours_);
}

Subject Subject::fromString(const std::string value, const std::string delimiter) {
    const auto values = parse(value, delimiter);
    if (values.size() != 2) {
        throw std::invalid_argument(
            "Subject requires [2] values to be parsed, got [" + std::to_string(values.size()) + "] in \"" + value + '\"');
    }
    return Subject(values[0], std::stoi(values[1]));
}
