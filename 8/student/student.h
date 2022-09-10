#pragma once

#include <string>

class Student {
public:
    Student(std::string name, std::string lastName);
    void setName(std::string name);
    void setLastName(std::string lastName);
    std::string getName();
    std::string getLastName();
    void setScores(int scores[]);
    void setAverageScore(double score);
    double getAverageScore();
    void save();
    ~Student();
private:
    std::string name_;
    std::string lastName_;
    int scores_[5];
    double averageScore_;
};