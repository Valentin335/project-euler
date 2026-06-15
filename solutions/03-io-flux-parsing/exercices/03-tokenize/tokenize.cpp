#include "tokenize.hpp"

#include <sstream>

std::vector<std::string> tokenize(const std::string& line) {
    std::istringstream flux(line);  // >> saute les espaces (même multiples)
    std::vector<std::string> result;
    std::string mot;
    while (flux >> mot) {
        result.push_back(mot);
    }
    return result;
}
