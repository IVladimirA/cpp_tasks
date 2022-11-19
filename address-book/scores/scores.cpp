#include "scores.h"
#include "../utils/parser/parser.h"

Scores::Scores(std::vector<int> scores)
    : scores_(scores)
    {}

std::string Scores::info() const {
    if (scores_.size() == 0) {
        return "";
    }
    std::string result = std::to_string(scores_[0]);
    for (size_t scoreIdx = 1; scoreIdx < scores_.size(); ++scoreIdx) {
        result += " " + std::to_string(scores_[scoreIdx]);
    }
    return result;
}

float Scores::average() const {
    int scoreSum = 0;
    for (const int score: scores_) {
        scoreSum += score;
    }
    return (float)scoreSum / (float)scores_.size();
}

std::string Scores::toString(const std::string delimiter) const {
    if (scores_.size() == 0) {
        return "";
    }
    std::string result = std::to_string(scores_[0]);
    for (size_t scoreIdx = 1; scoreIdx < scores_.size(); ++scoreIdx) {
        result += delimiter + std::to_string(scores_[scoreIdx]);
    }
    return result;
}

Scores Scores::fromString(const std::string value, const std::string delimiter) {
    const auto values = parse(value, delimiter);
    std::vector<int> scores;
    for (const std::string token: values) {
        scores.push_back(std::stoi(token));
    }
    return Scores(scores);
}
