#include "racine.hpp"

bool try_sqrt_int(int n, int& out) {
    /* n, out -> true + out=racine si carré parfait ; false sinon */
    (void)n;
    (void)out;
    return false;
}

int checked_sqrt_int(int n) {
    /* n -> racine ; throw domain_error si n<0, invalid_argument si pas un carré parfait */
    (void)n;
    return 0;
}
