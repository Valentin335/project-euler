#include "parse_int.hpp"

long long parse_int(const std::string& s) {
    /* "42" -> 42 ; lève std::invalid_argument si pas un entier complet */
    (void)s;
    return 0;
}

std::vector<long long> parse_ints(const std::string& line) {
    /* "1 2 3" -> {1, 2, 3} */
    (void)line;
    return {};
}
