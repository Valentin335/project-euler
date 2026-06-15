#include "racine.hpp"
#include <stdexcept>
bool try_sqrt_int(int n, int& out) {
    /* n, out -> true + out=racine si carré parfait ; false sinon */
    for (int i=1;i<=n;i++){
        if (i*i == n){
            out = i;
            return true;
        }
    }
    return false;
}

int checked_sqrt_int(int n) {
    /* n -> racine ; throw domain_error si n<0, invalid_argument si pas un carré parfait */
    int result = 0;
    if (n < 0){
        throw std::domain_error("Racine carree d'un nb negatif!");
    }
    if (try_sqrt_int(n, result)){
        return result;
    }
    throw std::invalid_argument("pas un carré parfait");  // entrée invalide
}
