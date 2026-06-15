// Corrigé de référence — parcours de vector.
#include "parcours.hpp"

#include <stdexcept>

int somme(const std::vector<int>& v) {
    int total = 0;
    for (const auto& x : v)  // lecture : référence const
        total += x;
    return total;
}

void mettre_au_carre(std::vector<int>& v) {
    for (auto& x : v)  // modification en place : référence mutable
        x *= x;
}

int compte_pairs(const std::vector<int>& v) {
    int n = 0;
    for (const auto& x : v)
        if (x % 2 == 0)
            ++n;
    return n;
}

int max_value(const std::vector<int>& v) {
    if (v.empty())  // pas de neutre pour un max : on refuse le vide
        throw std::invalid_argument("max_value: vecteur vide");
    // NOTE : avec <algorithm> on ferait *std::max_element(v.begin(), v.end()),
    // mais ici on muscle la boucle à la main.
    int best = v.front();
    for (const auto& x : v)
        if (x > best)
            best = x;
    return best;
}
