#include "runner.h"
#include "../../manager/manager.h"

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
                manager.add();
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
                manager.print();
                break;
            default:
                cout << "Incorrect option\n";
                break;
        }
    }
}

}; // namespace runner