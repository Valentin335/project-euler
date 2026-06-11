// =====================================================================
//  histogram_skeleton.cpp — À TOI DE JOUER
//
//  Implémente les deux fonctions déclarées dans histogram.hpp.
//  Les corps ci-dessous sont des bouchons (placeholders) : ils
//  compilent mais renvoient des valeurs neutres qui ne résolvent pas
//  l'exercice. Remplace chaque TODO par ta vraie implémentation.
// =====================================================================

#include "histogram.hpp"

// Indices : tu auras sans doute besoin de <cctype> pour std::tolower et
// std::isalpha. Pense à parcourir s avec une boucle range-for.

int count_char(const std::string& s, char c)
{
    // TODO: parcourir s (range-for) et incrementer un compteur a chaque
    //       fois qu'un caractere est egal a c.
    return 0;
}

std::vector<int> char_histogram(const std::string& s)
{
    // Bouchon : un histogramme de 26 cases toutes a zero. La taille est
    // bonne mais aucun comptage n'est fait : a toi de remplir les cases.
    // TODO: pour chaque caractere de s, ignorer ce qui n'est pas une
    //       lettre, mettre en minuscule, puis incrementer la bonne case.
    return std::vector<int>(26, 0);
}
