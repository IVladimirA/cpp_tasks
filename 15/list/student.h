#pragma once

#include <string>

class IdCard;

class Student {
public:
    IdCard* iCard;
    Student(std::string name, std::string lastName, IdCard* id = nullptr);
    void setName(std::string name);
    void setLastName(std::string lastName);
    std::string getName() const;
    std::string getLastName() const;
    void setScores(int scores[]);
    void setAverageScore(double score);
    double getAverageScore() const;
    void save() const;
    void print() const;
    ~Student();
    friend bool operator<(const Student& lhs, const Student& rhs);
    friend bool operator>(const Student& lhs, const Student& rhs);
    friend bool operator==(const Student& lhs, const Student& rhs);
    friend bool operator!=(const Student& lhs, const Student& rhs);
private:
    std::string name_;
    std::string lastName_;
    int scores_[5];
    double averageScore_;
};