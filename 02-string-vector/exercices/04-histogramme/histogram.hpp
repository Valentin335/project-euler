#pragma once
// histogram.hpp — signatures imposées. NE PAS MODIFIER.

#include <string>
#include <vector>
#include <cstddef>

int count_char(const std::string& s, char c);          // (s, c) → nombre d'occurrences de c dans s
std::vector<int> char_histogram(const std::string& s);  // s → 26 cases a..z (casse ignorée, non-lettres ignorées)
