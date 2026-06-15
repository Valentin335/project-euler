// =====================================================================
//  describe.cpp — CORRIGÉ DE RÉFÉRENCE
//
//  Quatre surcharges résolues par le type de l'argument. Attention :
//  un littéral "x" (const char*) préfère bool, pas string.
// =====================================================================
#include "describe.hpp"

#include <format>  // std::format

std::string describe(int n) {
    return "entier " + std::to_string(n);  // to_string : int → texte
}

std::string describe(double d) {
    return std::format("flottant {}", d);  // format C++20, {} = l'argument
}

std::string describe(const std::string& s) {
    return "texte: " + s;
}

std::string describe(bool b) {
    return b ? "booleen vrai" : "booleen faux";
}
