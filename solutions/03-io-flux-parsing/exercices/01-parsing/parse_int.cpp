#include "parse_int.hpp"

#include <cstddef>
#include <sstream>

long long parse_int(const std::string& s) {
    std::size_t pos = 0;
    // std::stoll lève std::invalid_argument sur "" / non numérique.
    long long n = std::stoll(s, &pos);
    // ... mais accepte un préfixe ("12a") : on exige la chaîne entière.
    if (pos != s.size()) {
        throw std::invalid_argument("entier incomplet : " + s);
    }
    return n;
}

std::vector<long long> parse_ints(const std::string& line) {
    std::istringstream flux(line);  // >> saute les espaces (même multiples)
    std::vector<long long> result;
    std::string mot;
    while (flux >> mot) {
        result.push_back(parse_int(mot));
    }
    return result;
}
