#include "student.h"
#include "group.h"

#include <algorithm>
#include <iostream>

size_t Group::size() const
{
    return students_.size();
}

void Group::add(Student student)
{
    students_.push_back(student);
}

void Group::erase(Student student)
{
    students_.remove(student);
}

Student Group::findByName(std::string name, std::string lastName) const
{
    auto iterator = find(students_.begin(), students_.end(), Student(name, lastName));
    return *iterator;
}

void Group::sort()
{
    students_.sort();
}

void Group::print() const
{
    auto iterator = students_.begin();
    while (iterator != students_.end()) {
        (iterator++)->print();
    }
    std::cout << '\n';
}