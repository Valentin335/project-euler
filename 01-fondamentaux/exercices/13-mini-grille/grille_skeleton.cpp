// =====================================================================
//  grille_skeleton.cpp — À TOI DE JOUER
//
//  Implémente les trois fonctions déclarées dans grille.hpp.
//  Les corps ci-dessous sont des bouchons (placeholders) : ils
//  compilent mais renvoient des valeurs neutres. Remplace chaque TODO
//  par ta vraie implémentation.
// =====================================================================

#include "grille.hpp"

Grid make_grid(std::size_t rows, std::size_t cols, int fill)
{
    // TODO: construire une grille de `rows` lignes et `cols` colonnes
    // remplie avec `fill`. Pense au constructeur de std::vector qui prend
    // une taille et une valeur de remplissage.
    // (Bouchon : on renvoie une grille 1x1 « factice » pour ne pas
    // planter quand le test indexe g[0]. Les dimensions sont fausses.)
    return Grid{{0}};
}

int grid_sum(const Grid& g)
{
    // TODO: parcourir toutes les cases avec un range-for imbriqué et
    // accumuler la somme.
    return 0;
}

Grid transpose(const Grid& g)
{
    // TODO: construire la grille transposee. La case (i, j) du resultat
    // vaut la case (j, i) de `g`. Utilise g.at() pour au moins un acces.
    return {};
}
