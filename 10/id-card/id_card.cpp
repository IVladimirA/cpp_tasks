#include "id_card.h"

IdCard::IdCard() : number(0), category("not set") {}

IdCard::IdCard(int num) : number(num), category("not set") {}

IdCard::IdCard(int num, std::string categ) : number(num), category(categ) {}
