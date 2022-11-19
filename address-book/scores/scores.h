#pragma once

#include <string>
#include <vector>

class Scores {
public:
    Scores(std::vector<int> scores = {});
    std::string info() const;
    float average() const;
    std::string toString(const std::string delimiter = ";") const;
    static Scores fromString(const std::string value, const std::string delimiter = ";");
private:
    std::vector<int> scores_;
};
