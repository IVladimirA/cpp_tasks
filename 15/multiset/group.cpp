#include "group.h"

#include <algorithm>
#include <iostream>

size_t Group::size() const
{
    return students_.size();
}

void Group::add(Student* student)
{
    students_.insert(student);
}

void Group::erase(Student* student)
{
    students_.erase(student);
}

Student* Group::findByName(std::string name, std::string lastName) const
{
    Student* tmp = new Student(name, lastName);
    auto iterator = students_.lower_bound(tmp);
    delete tmp;
    return *iterator;
}

void Group::print() const
{
    auto iterator = students_.begin();
    while (iterator != students_.end()) {
        (*iterator++)->print();
    }
    std::cout << '\n';
}