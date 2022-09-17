#pragma once

#include <string>

class IdCard {
public:
    int number;
    std::string category;
    IdCard();
    IdCard(int num);
    IdCard(int num, std::string category);
};