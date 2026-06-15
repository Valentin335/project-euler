// =====================================================================
//  palindrome.cpp — CORRIGÉ DE RÉFÉRENCE
//
//  reverse : construire la chaîne depuis ses itérateurs inverses.
//  is_palindrome : normaliser (minuscules, sans espaces) puis comparer
//  la chaîne à elle-même lue à l'envers via std::equal.
// =====================================================================
#include "palindrome.hpp"

#include <algorithm>  // std::equal
#include <cctype>     // std::tolower, std::isspace

// Construit la chaîne à partir de la paire d'itérateurs inverses.
std::string reverse(const std::string& s) {
    return std::string(s.rbegin(), s.rend());
}

bool is_palindrome(const std::string& s) {
    // Normalisation : minuscules, espaces retirés (cast en unsigned char
    // obligatoire avant std::tolower/std::isspace).
    std::string norm;
    norm.reserve(s.size());
    for (unsigned char c : s) {
        if (!std::isspace(c)) {
            norm.push_back(static_cast<char>(std::tolower(c)));
        }
    }
    // Comparaison symétrique : norm == norm inversée.
    return std::equal(norm.begin(), norm.end(), norm.rbegin());
}
