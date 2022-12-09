#include "manager.h"

#include <fstream>

namespace addressBook {

using namespace people;

Manager::Manager(std::vector<std::unique_ptr<Human>> people)
    : people_(std::move(people))
    {}

const std::vector<std::unique_ptr<people::Human>>& Manager::getPeople() const {
    return people_;
}
    
void Manager::save(std::string filePath, std::string delimiter) const {
    std::ofstream outFile(filePath);
    if (!outFile.is_open()) {
        throw std::invalid_argument("Cannot open file: " + filePath);
    }
    for (const auto& human: people_) {
        if (dynamic_cast<Student*>(human.get())) {
            outFile << "s" << delimiter;
        } else {
            outFile << "t" << delimiter;
        }
        outFile << human->toString(delimiter) << '\n';
    }
}

void Manager::load(std::string filePath, std::string delimiter) {
    people_.clear();

    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        throw std::invalid_argument("Cannot open file: " + filePath);
    }

    std::string nextString;
    while (inFile >> nextString)
    {
        switch (nextString[0]) {
            case 's':
                nextString.erase(0, 2);
                people_.push_back(std::make_unique<Student>(Student::fromString(std::move(nextString))));
                break;
            case 't':
                nextString.erase(0, 2);
                people_.push_back(std::make_unique<Teacher>(Teacher::fromString(std::move(nextString))));
                break;
            default:
                throw std::invalid_argument("Incorrect file format");
                break;
        }
    }
}

void Manager::add(std::unique_ptr<people::Human>&& human) {
    people_.push_back(std::move(human));
}

void Manager::erase(size_t index) {
    if (index >= people_.size()) {
        return;
    }
    people_.erase(std::next(people_.begin(), index));
}

void Manager::clear() {
    people_.clear();
}

size_t Manager::size() const {
    return people_.size();
}

}; // namespace addressBook
