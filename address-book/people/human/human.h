#pragma once

#include <string>

namespace people {

class Human {
public:
    Human(std::string name, std::string lastName, std::string patronymic, std::string phone = "");
    std::string fullName() const;
    virtual std::string info() const;
    virtual std::string toString(const std::string delimiter = ";") const;
    static Human fromString(const std::string value, const std::string delimiter = ";");
private:
    std::string name_;
    std::string lastName_;
    std::string patronymic_;
    std::string phoneNumber_;
};

}; //namespace people
