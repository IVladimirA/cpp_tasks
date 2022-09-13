#include "student.h"
#include "teacher.h"

#include <iostream>

int main() {
    using namespace std;

    Student student("Vladimir", "Ivanov", "Anatol\'evich", {5, 5, 3, 4, 5});
    Teacher teacher("Dmitry", "Sergeev", "Sergeevich", 100500);

    Human* people[2];
    people[0] = &student;
    people[1] = &teacher;
    for (size_t i = 0; i < 2; ++i) {
        cout << people[i]->info() << '\n';
    }
    return 0;  
}
