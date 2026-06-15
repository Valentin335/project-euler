#include "constref.hpp"
#include <stdexcept>
std::size_t length(const std::string& s) {
    /* s -> taille de s */
    return s.size();
}

char first_char(const std::string& s) {
    /* s -> 1er char ; throw std::invalid_argument si vide */
    if (s.empty()){
        throw std::invalid_argument("Chaine vide!");
    }
    return s.front();
}

void append_excl(std::string& s) {
    /* s -> s + " !" en place */
    s = s + " !";
}
