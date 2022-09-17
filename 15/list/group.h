#pragma once

#include <list>
#include <string>

class Student;

class Group {
public:
    size_t size() const;
    void add(Student student);
    void erase(Student student);
    Student findByName(std::string name, std::string lastName) const;
    void sort();
    void print() const;
private:
    std::list<Student> students_;
};