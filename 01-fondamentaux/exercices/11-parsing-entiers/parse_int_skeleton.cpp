// Exercice 11 — Parsing robuste d'entiers.
// Complete le corps des fonctions ci-dessous. Les signatures sont imposees
// par parse_int.hpp : ne les modifie pas.
#include "parse_int.hpp"

#include <stdexcept>
#include <string>

long long parse_int(const std::string& s) {
    // TODO: convertir s en long long et lancer std::invalid_argument si s
    // n'est pas un entier complet valide (ex : "12a", "", "  ").
    // Astuce : std::stoll fait une grande partie du travail, mais il accepte
    // les chaines qui COMMENCENT par un entier ("12a" donne 12). Tu dois
    // verifier que TOUTE la chaine a bien ete consommee.
    return 0;
}

std::vector<long long> parse_ints(const std::string& line) {
    // TODO: decouper line en entiers separes par des espaces (espaces
    // multiples a ignorer), et renvoyer le vecteur correspondant.
    // "" doit renvoyer un vecteur vide.
    return {};
}
