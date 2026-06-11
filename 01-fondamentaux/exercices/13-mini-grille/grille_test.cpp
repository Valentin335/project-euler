// =====================================================================
//  grille_test.cpp — Tests fournis (NE PAS MODIFIER)
//
//  Compile-le avec ton grille_skeleton.cpp pour vérifier ta solution.
//  Tant que les corps sont des bouchons, des tests échouent : c'est
//  normal. Ton but est de tous les faire passer.
// =====================================================================

#include "check.hpp"
#include "grille.hpp"

#include <vector>
#include <cstddef>

int main()
{
    // --- make_grid ---------------------------------------------------
    auto g = make_grid(2, 3, 0);
    CHECK_EQ(g.size(), std::size_t{2});
    CHECK_EQ(g[0].size(), std::size_t{3});
    CHECK_EQ(g[0][0], 0);

    // --- grid_sum ----------------------------------------------------
    // Astuce : les accolades imbriquées d'un littéral Grid{...}
    // contiennent des virgules. Le préprocesseur des macros les prendrait
    // pour des séparateurs d'arguments. On déclare donc les grilles dans
    // des variables locales avant de les passer à CHECK_EQ.
    Grid carre{{1, 2}, {3, 4}};
    CHECK_EQ(grid_sum(carre), 10);
    CHECK_EQ(grid_sum(Grid{}), 0);

    // --- transpose ---------------------------------------------------
    Grid rect{{1, 2, 3}, {4, 5, 6}};
    Grid rect_t{{1, 4}, {2, 5}, {3, 6}};
    CHECK_EQ(transpose(rect), rect_t);

    // --- cas limites : make_grid ------------------------------------
    // Plus petite grille possible : 1 ligne, 1 colonne, remplie de 7.
    auto unit = make_grid(1, 1, 7);
    CHECK_EQ(unit.size(), std::size_t{1});
    CHECK_EQ(unit.at(0).size(), std::size_t{1});
    CHECK_EQ(unit.at(0).at(0), 7);

    // Grille « colonne » : 3 lignes d'une seule colonne, remplie de 0.
    auto colonne = make_grid(3, 1, 0);
    CHECK_EQ(colonne.size(), std::size_t{3});
    CHECK_EQ(colonne.at(0).size(), std::size_t{1});
    CHECK_EQ(colonne.at(0).at(0), 0);

    // --- cas limites : grid_sum -------------------------------------
    // La somme doit gérer les valeurs négatives : -1 -2 +3 +4 = 4.
    Grid signes{{-1, -2}, {3, 4}};
    CHECK_EQ(grid_sum(signes), 4);

    // --- cas limites : transpose ------------------------------------
    // Grille « ligne » 1xN : la transposée est une grille « colonne » Nx1.
    Grid ligne{{1, 2, 3}};
    Grid ligne_t{{1}, {2}, {3}};
    CHECK_EQ(transpose(ligne), ligne_t);

    // Grille « colonne » Nx1 : la transposée est une grille « ligne » 1xN.
    Grid col{{1}, {2}};
    Grid col_t{{1, 2}};
    CHECK_EQ(transpose(col), col_t);

    // Transposer deux fois redonne la grille de depart (involution).
    Grid g2{{1, 2, 3}, {4, 5, 6}};
    CHECK_EQ(transpose(transpose(g2)), g2);

    return check::report();
}
