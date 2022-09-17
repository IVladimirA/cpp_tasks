#pragma once

#include <string>
#include <map>

struct StudentGrade {
    std::string studentName;
    char grade;
};

class Grades {
public:
    size_t size() const;
    void setGrade(StudentGrade grade);
    void erase(std::string name);
    void print() const;
private:
    std::map<std::string, StudentGrade> grades_;
};