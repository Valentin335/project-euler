// Exercice 12 — Absence de valeur avec std::optional.
// Complete le corps des fonctions ci-dessous. Les signatures sont imposees
// par optionnel.hpp : ne les modifie pas.
#include "optionnel.hpp"

std::optional<std::size_t> index_of(const std::vector<int>& v, int target) {
    // TODO: parcourir v et renvoyer l'indice du premier element egal a target.
    // Si aucun element ne correspond, renvoyer std::nullopt.
    // INTERDIT : ne renvoie pas un indice "magique" comme la taille du vecteur
    // ou une valeur sentinelle ; c'est justement le role de std::nullopt.
    // Valeur bidon de depart (a remplacer) : renvoie toujours l'indice 0.
    return std::size_t{0};
}

std::optional<int> safe_divide(int a, int b) {
    // TODO: si b == 0, renvoyer std::nullopt ; sinon renvoyer a / b.
    // Valeur bidon de depart (a remplacer) : renvoie toujours 0.
    return 0;
}
