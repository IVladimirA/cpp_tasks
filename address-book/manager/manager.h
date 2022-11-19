#pragma once

#include "../people/student/student.h"
#include "../people/teacher/teacher.h"

#include <memory>

namespace addressBook {

class Manager {
public:
    Manager(std::vector<std::unique_ptr<people::Human>> people = {});
    void print() const;
    void save(std::string filePath, std::string delimiter = ";") const;
    void load(std::string filePath, std::string delimiter = ";");
    void add();
    void erase(size_t index);
    void clear();
private:
    std::vector<std::unique_ptr<people::Human>> people_;
};

}; // namespace addressBook