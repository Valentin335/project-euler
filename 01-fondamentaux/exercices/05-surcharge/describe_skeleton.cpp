#include "describe.hpp"
#include <format>

std::string describe(int n) {
    /* 42 → "entier 42" */
    return "entier "+ std::to_string(n);
}

std::string describe(double d) {
    /* 3.5 → "flottant 3.5" */
    return "flottant " + std::to_string(d);
}

std::string describe(const std::string& s) {
    /* "bonjour" → "texte: bonjour" */

    return "texte: " + s;
}

std::string describe(bool b) {
    /* true → "booleen vrai" */
    if (b){
        return "booleen vrai";
    }
    return "booleen faux";
}
