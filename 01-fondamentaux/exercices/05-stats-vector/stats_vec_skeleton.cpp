// =====================================================================
//  stats_vec_skeleton.cpp — À TOI DE JOUER
//
//  Implémente les trois fonctions déclarées dans stats_vec.hpp.
//  Les corps ci-dessous sont des bouchons (placeholders) : ils
//  compilent mais renvoient des valeurs neutres et ne lèvent aucune
//  exception. Remplace chaque TODO par ta vraie implémentation.
// =====================================================================

#include "stats_vec.hpp"

#include <stdexcept>   // std::invalid_argument

int sum(const std::vector<int>& v)
{
    // TODO: parcourir v (range-for) et accumuler la somme.
    return 0;
}

double mean(const std::vector<int>& v)
{
    // TODO: si v est vide, lever std::invalid_argument.
    // TODO: sinon, renvoyer sum(v) / taille (attention au type !).
    return 0.0;
}

int max_value(const std::vector<int>& v)
{
    // TODO: si v est vide, lever std::invalid_argument.
    // TODO: sinon, parcourir v pour trouver le plus grand élément.
    return 0;
}
