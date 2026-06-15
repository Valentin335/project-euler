#include "describe.hpp"

std::string describe(int n) {
    /* 42 → "entier 42" */
    (void)n;
    return {};
}

std::string describe(double d) {
    /* 3.5 → "flottant 3.5" */
    (void)d;
    return {};
}

std::string describe(const std::string& s) {
    /* "bonjour" → "texte: bonjour" */
    (void)s;
    return {};
}

std::string describe(bool b) {
    /* true → "booleen vrai" */
    (void)b;
    return {};
}
