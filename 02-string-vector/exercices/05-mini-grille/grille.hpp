#pragma once
// NE PAS MODIFIER : signatures imposées.
#include <vector>
#include <cstddef>

using Grid = std::vector<std::vector<int>>;

// (rows, cols, fill) → grille rows x cols remplie de fill
Grid make_grid(std::size_t rows, std::size_t cols, int fill);

// g → somme de tous les éléments
int grid_sum(const Grid& g);

// g → transposée : résultat(i,j) = g(j,i)
Grid transpose(const Grid& g);
