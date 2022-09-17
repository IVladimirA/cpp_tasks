#include "id_card.h"
#include "group.h"

#include <iostream>

int main() {
    using namespace std;
    
    IdCard idc(123, "basic");
    IdCard idc2(31, "advanced");
    IdCard idc3(47, "premium");

    Group students;
    Student st1("D", "E", &idc);
    students.add(&st1);
    Student st2("E", "F", &idc2);
    students.add(&st2);
    Student st3("F", "G", &idc3);
    students.add(&st3);
    Student st4("A", "B", &idc);
    students.add(&st4);
    Student st5("B", "C", &idc2);
    students.add(&st5);
    Student st6("C", "D", &idc3);
    students.add(&st6);
    
    cout << students.size() << '\n';
    students.print();
    students.erase(&st6);
    students.print();
    students.findByName("B", "C")->print();
    return 0;
}
