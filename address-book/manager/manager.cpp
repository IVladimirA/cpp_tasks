#include "manager.h"
#include "../utils/creators/creators.h"

#include <fstream>
#include <iostream>

namespace addressBook {

using namespace people;

Manager::Manager(std::vector<std::unique_ptr<Human>> people)
    : people_(std::move(people))
    {}

void Manager::print() const {
    for (size_t humanIdx = 0; humanIdx < people_.size(); ++humanIdx) {
        std::cout << humanIdx + 1 << ") " << people_[humanIdx]->info() << '\n';
    }
}
    
void Manager::save(std::string filePath, std::string delimiter) const {
    std::ofstream outFile(filePath);
    for (const auto& human: people_) {
        if (dynamic_cast<Student*>(human.get())) {
            outFile << "s" << delimiter;
        } else {
            outFile << "t" << delimiter;
        }
        outFile << human->toString(delimiter) << '\n';
    }
    outFile.close();
}

void Manager::load(std::string filePath, std::string delimiter) {
    people_.clear();

    std::ifstream inFile(filePath);
    std::string nextString;
    while (inFile >> nextString)
    {
        switch (nextString[0]) {
            case 's':
                nextString.erase(0, 2);
                people_.push_back(std::make_unique<Student>(Student::fromString(nextString)));
                break;
            case 't':
                nextString.erase(0, 2);
                people_.push_back(std::make_unique<Teacher>(Teacher::fromString(nextString)));
                break;
            default:
                throw std::logic_error("Incorrect file format");
                break;
        }
    }
    inFile.close();
}

void Manager::add() {
    std::cout << "Choose person (1 - student, 2 - teacher): ";
    int person;
    std::cin >> person;
    switch (person)
    {
    case 1:
        people_.push_back(std::make_unique<Student>(creators::student()));
        break;
    case 2:
        people_.push_back(std::make_unique<Teacher>(creators::teacher()));
        break;
    default:
        std::cout << "Incorrect person type\n";
    }
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

}; // namespace addressBook
