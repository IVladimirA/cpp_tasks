#pragma once

#include "student.h"

#include <set>
#include <string>

class Group {
public:
    size_t size() const;
    void add(Student* student);
    void erase(Student* student);
    Student* findByName(std::string name, std::string lastName) const;
    void print() const;
private:
    std::multiset<Student*, CompareStudent> students_;
};