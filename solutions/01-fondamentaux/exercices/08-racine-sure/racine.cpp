// Corrigé de référence — « Racine sûre ».
#include "racine.hpp"
#include <stdexcept>

bool try_sqrt_int(int n, int& out) {
    if (n < 0)
        return false;  // pas de racine réelle : on signale par le code de retour
    for (int i = 0; i * i <= n; ++i) {
        if (i * i == n) {
            out = i;     // succès : on écrit le résultat dans le paramètre out
            return true;
        }
    }
    return false;  // n positif mais pas un carré parfait
}

int checked_sqrt_int(int n) {
    if (n < 0)
        throw std::domain_error("n négatif");  // erreur de domaine
    for (int i = 0; i * i <= n; ++i) {
        if (i * i == n)
            return i;  // carré parfait trouvé
    }
    throw std::invalid_argument("pas un carré parfait");  // entrée invalide
}
