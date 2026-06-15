#include "histogram.hpp"

#include <algorithm>
#include <cctype>

int count_char(const std::string& s, char c) {
    // std::count parcourt [begin, end) et compte les égalités.
    return static_cast<int>(std::count(s.begin(), s.end(), c));
}

std::vector<int> char_histogram(const std::string& s) {
    std::vector<int> histo(26, 0);  // 26 cases a..z, initialisées à 0
    for (char ch : s) {
        const auto uc = static_cast<unsigned char>(ch);  // évite l'UB sur char négatif
        if (std::isalpha(uc)) {
            ++histo[static_cast<std::size_t>(std::tolower(uc) - 'a')];
        }
    }
    return histo;
}
