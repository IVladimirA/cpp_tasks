#include <iostream>
#include <string>
#include <vector>

struct StudentGrade {
    std::string name;
    char grade;
};

class GradeMap {
private:
    std::vector<StudentGrade> grades_;
public:
    GradeMap() {}
    char& operator[](const std::string& name) {
        for (auto& studentGrade: grades_) {
            if (studentGrade.name == name) {
                return studentGrade.grade;
            }
        }
        grades_.push_back({name, ' '});
        return grades_.back().grade;
    }
};

int main() {
    using namespace std;
    GradeMap grades;
    grades["John"] = 'A';
    grades["Martin"] = 'B';
    cout << "John has a grade of " << grades["John"] << endl;
    cout << "Martin has a grade of " << grades["Martin"] << endl;
    cout << "New name and grade?" << endl;
    string name;
    char grade;
    cin >> name >> grade;
    grades[name] = grade;
    std::cout << name << " has a grade of " << grades[name] << endl;
    return 0;   
}
