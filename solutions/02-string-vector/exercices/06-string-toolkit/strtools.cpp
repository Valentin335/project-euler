// =====================================================================
//  strtools.cpp — CORRIGÉ DE RÉFÉRENCE
//
//  to_upper : std::toupper sur chaque caractère (cast unsigned char).
//  trim : bornes via find_first_not_of / find_last_not_of, puis substr.
//  starts_with : s.rfind(prefix, 0) == 0 (le préfixe est en position 0).
// =====================================================================
#include "strtools.hpp"

#include <cctype>  // std::toupper

std::string to_upper(const std::string& s) {
    std::string out;
    out.reserve(s.size());
    // Cast en unsigned char obligatoire avant std::toupper.
    for (unsigned char c : s) {
        out.push_back(static_cast<char>(std::toupper(c)));
    }
    return out;
}

std::string trim(const std::string& s) {
    const std::size_t first = s.find_first_not_of(' ');
    // Que des espaces (ou chaîne vide) : il ne reste rien.
    if (first == std::string::npos) {
        return "";
    }
    const std::size_t last = s.find_last_not_of(' ');
    return s.substr(first, last - first + 1);
}

bool starts_with(const std::string& s, const std::string& prefix) {
    // rfind(prefix, 0) cherche prefix sans dépasser la position 0 :
    // il renvoie 0 si, et seulement si, s commence par prefix.
    return s.rfind(prefix, 0) == 0;
}
