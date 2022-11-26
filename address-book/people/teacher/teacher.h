#pragma once

#include "../human/human.h"
#include "../../subject/subject.h"

#include <string>

namespace people {

class Teacher : public Human {
public:
    Teacher(std::string name, std::string lastName, std::string patronymic, std::string phone, Subject subject);
    std::string info() const;
    std::string toString(const std::string delimiter = ";") const;
    static Teacher fromString(const std::string value, const std::string delimiter = ";");
private:
    Subject subject_;
};

}; //namespace people
