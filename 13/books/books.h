#pragma once

#include <iostream>
#include <string>

class Item {
public:
    virtual void input() {
        std::cout << "name: ";
        std::cin >> name_;
        std::cout << "price: ";
        std::cin >> price_;
    }
    virtual void print() const {
        std::cout << "\nname: " << name_;
        std::cout << "\nprice" << price_;
    }
private:
    std::string name_;
    double price_;
};

class PaperBook : public Item {
public:
    void input() {
        Item::input();
        std::cout << "page count: ";
        std::cin >> pages_;
    }
    void print() const {
        Item::print();
        std::cout << "\npage count: " << pages_;
    }
private:
    int pages_;
};

class AudioBook : public Item {
public:
    void input() {
        Item::input();
        std::cout << "time: ";
        std::cin >> time_;
    }
    void print() const {
        Item::print();
        std::cout << "\ntime: " << time_;
    }
private:
    double time_;
};
