#pragma once

#include <string>

class Subject {
public:
    Subject(std::string name, int hours);
    std::string info() const;
    std::string toString(const std::string delimiter = ";") const;
    static Subject fromString(const std::string value, const std::string delimiter = ";");
private:
    std::string name_;
    int hours_;
};
