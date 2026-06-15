#pragma once
// NE PAS MODIFIER — signatures imposées.
#include <string>

// s → s lue de droite à gauche.
std::string reverse(const std::string& s);

// s → true si palindrome (casse et espaces ignorés, ASCII).
bool is_palindrome(const std::string& s);
