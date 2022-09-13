#pragma once

#include <string>

class Human {
public:
    Human(std::string name, std::string lastName, std::string patronymic = "");
    std::string fullName() const;
    virtual std::string info() const;
private:
    std::string name_;
    std::string lastName_;
    std::string patronymic_;
};