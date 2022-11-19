#include "subject.h"
#include "../utils/parser/parser.h"

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
    return Subject(values[0], std::stoi(values[1]));
}
