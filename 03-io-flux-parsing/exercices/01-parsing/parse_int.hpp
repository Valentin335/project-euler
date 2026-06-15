#pragma once
// NE PAS MODIFIER — signatures imposées.

#include <string>
#include <vector>
#include <stdexcept>

// "42" -> 42 ; lève std::invalid_argument si la chaîne n'est pas
// un entier complet (vide, caractères parasites...).
long long parse_int(const std::string& s);

// "1 2 3" -> {1, 2, 3} ; découpe sur les espaces, parse chaque mot.
std::vector<long long> parse_ints(const std::string& line);
