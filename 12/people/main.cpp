#include "student.h"
#include "teacher.h"

#include <iostream>

int main() {
    using namespace std;

    Student student("Vladimir", "Ivanov", "Anatol\'evich", {5, 5, 3, 4, 5});
    Teacher teacher("Dmitry", "Sergeev", "Sergeevich", 100500);

    cout << "Sturent: " << student.fullName() << " has average grade score = " << student.averageScore() << '\n';
    cout << "Teacher: " << teacher.fullName() << " has work hours = " << teacher.workHours() << '\n';
    return 0;  
}
