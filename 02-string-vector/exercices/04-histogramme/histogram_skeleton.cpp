#include "histogram.hpp"

int count_char(const std::string& s, char c) {
    /* (s, c) → nombre d'occurrences de c dans s */
    (void)s;
    (void)c;
    return 0;
}

std::vector<int> char_histogram(const std::string& s) {
    /* s → 26 cases a..z (casse ignorée, non-lettres ignorées) */
    (void)s;
    return std::vector<int>(26, 0);
}
