#include "grille.hpp"

Grid make_grid(std::size_t rows, std::size_t cols, int fill) {
    /* (rows, cols, fill) → grille rows x cols remplie de fill */
    (void)rows;
    (void)cols;
    (void)fill;
    return {};
}

int grid_sum(const Grid& g) {
    /* g → somme de tous les éléments */
    (void)g;
    return 0;
}

Grid transpose(const Grid& g) {
    /* g → transposée : resultat(i,j) = g(j,i) */
    (void)g;
    return {};
}
