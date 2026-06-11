// Exercice 03 — const-correctness & références.
// Complète le corps des fonctions ci-dessous. Les signatures sont imposées
// par constref.hpp : ne les modifie pas.
//
// Observe les signatures : `const std::string&` (lecture seule, sans copie)
// versus `std::string&` (modification en place). C'est tout l'enjeu ici.
#include "constref.hpp"

#include <stdexcept>  // pour std::invalid_argument (à toi de t'en servir)

std::size_t length(const std::string& s) {
    // TODO: renvoyer la taille de s, sans en faire de copie.
    return 0;
}

char first_char(const std::string& s) {
    // TODO: renvoyer le premier caractère de s.
    // Si s est vide, lève une std::invalid_argument.
    return ' ';
}

void append_excl(std::string& s) {
    // TODO: ajouter " !" à la fin de s, en place (s est modifié).
}
