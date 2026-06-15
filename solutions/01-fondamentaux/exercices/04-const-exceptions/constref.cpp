// Corrigé de référence — « Const et exceptions ».
#include "constref.hpp"
#include <stdexcept>

std::size_t length(const std::string& s) {
    return s.size();  // const& : lecture sans copie
}

char first_char(const std::string& s) {
    if (s.empty())
        throw std::invalid_argument("chaîne vide");  // signale l'erreur
    return s.front();  // accès au 1er caractère
}

void append_excl(std::string& s) {
    s += " !";  // modification en place via référence non-const
}
