#include "grades.h"

#include <iostream>

int main() {
    using namespace std;
    Grades grades;
    cout << grades.size() << '\n';
    grades.setGrade({"A", 'F'});
    grades.setGrade({"B", 'E'});
    grades.setGrade({"C", 'D'});
    grades.setGrade({"D", 'C'});
    grades.setGrade({"E", 'B'});
    grades.setGrade({"F", 'A'});
    cout << grades.size() << '\n';
    grades.print();
    grades.erase("D");
    grades.print();
    
    return 0;
}
