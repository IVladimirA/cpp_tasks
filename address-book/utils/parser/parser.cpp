#include "parser.h"

std::vector<std::string> parse(std::string value, const std::string delimiter) {
    std::vector<std::string> result;
    size_t position;
    std::string token;
    while ((position = value.find(delimiter)) != std::string::npos) {
        token = value.substr(0, position);
        result.push_back(token);
        value.erase(0, position + delimiter.length());
    }
    result.push_back(value);
    return result;
}
