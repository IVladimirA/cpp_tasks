#include "id_card.h"
#include "student.h"
#include "group.h"

#include <iostream>

int main() {
    using namespace std;
    
    IdCard idc(123, "basic");
    IdCard idc2(31, "advanced");
    IdCard idc3(47, "premium");

    Group students;
    students.add({"D", "E", &idc});
    students.add({"E", "F", &idc2});
    students.add({"F", "G", &idc3});
    students.add({"A", "B", &idc});
    students.add({"B", "C", &idc2});
    students.add({"C", "D", &idc3});
    
    cout << students.size() << '\n';
    students.print();
    students.sort();
    students.print();
    students.erase({"C", "D"});
    students.print();
    students.findByName("B", "C").print();
    return 0;
}
