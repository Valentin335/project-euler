#pragma once
// NE PAS MODIFIER — signatures imposées.
#include <string>

// s → s avec toutes les lettres en majuscules.
std::string to_upper(const std::string& s);

// s → s sans les espaces de début et de fin.
std::string trim(const std::string& s);

// (s, prefix) → true si s commence par prefix.
bool starts_with(const std::string& s, const std::string& prefix);
