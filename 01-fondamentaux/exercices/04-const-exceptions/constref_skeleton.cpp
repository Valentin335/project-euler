#include "constref.hpp"
#include <stdexcept>

std::size_t length(const std::string& s) {
    /* s -> taille de s */
    (void)s;
    return 0;
}

char first_char(const std::string& s) {
    /* s -> 1er char ; throw std::invalid_argument si vide */
    (void)s;
    return '?';
}

void append_excl(std::string& s) {
    /* s -> s + " !" en place */
    (void)s;
}
