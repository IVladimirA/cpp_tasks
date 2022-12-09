#include "runner.h"
#include "../../manager/manager.h"
#include "../../utils/creators/creators.h"

#include <iostream>

namespace runner {

namespace {

void printMenu() {
    using namespace std;
    cout << "\nMenu:\n"
         << "0) Exit\n"
         << "1) Load from file\n"
         << "2) Save to file\n"
         << "3) Add person\n"
         << "4) Erase person\n"
         << "5) Clear all\n"
         << "6) Print all\n";
}

void addHuman(addressBook::Manager& manager) {
    std::cout << "Choose person (1 - student, 2 - teacher): ";
    int person;
    std::cin >> person;
    switch (person)
    {
    case 1:
        manager.add(std::move(std::make_unique<people::Student>(creators::student())));
        break;
    case 2:
        manager.add(std::move(std::make_unique<people::Teacher>(creators::teacher())));
        break;
    default:
        std::cout << "Incorrect person type\n";
        break;
    }
}

void printPeople(const addressBook::Manager& manager) {
    const auto& people = manager.getPeople();
    for (size_t humanIdx = 0; humanIdx < people.size(); ++humanIdx) {
        std::cout << humanIdx + 1 << ") " << people[humanIdx]->info() << '\n';
    }
}

}; // namespace

void run() {
    using namespace std;
    addressBook::Manager manager;
    while (true) {
        printMenu();
        std::cout << "Option: ";
        int option;
        std::cin >> option;
        cout << '\n';
        std::string filePath;
        std::string delimiter;
        size_t number;
        try {
        switch (option) {
            case 0:
                return;
            case 1:
                cout << "Enter file path: ";
                cin >> filePath;
                cout << "Enter delimiter: ";
                cin >> delimiter;
                manager.load(std::move(filePath), std::move(delimiter));
                break;
            case 2:
                cout << "Enter file path: ";
                cin >> filePath;
                cout << "Enter delimiter: ";
                cin >> delimiter;
                manager.save(std::move(filePath), std::move(delimiter));
                break;
            case 3:
                addHuman(manager);
                break;
            case 4:
                cout << "Enter number of person to erase: ";
                cin >> number;
                manager.erase(number - 1);
                break;
            case 5:
                manager.clear();
                break;
            case 6:
                printPeople(manager);
                break;
            default:
                cout << "Incorrect option\n";
                break;
        }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << '\n';
        }
    }
}

}; // namespace runner