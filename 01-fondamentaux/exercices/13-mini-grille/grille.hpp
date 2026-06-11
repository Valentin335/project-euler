#pragma once
// =====================================================================
//  grille.hpp — Signatures imposées de l'exercice « Mini-grille ».
//
//  NE PAS MODIFIER ce fichier : il décrit le contrat que ta solution
//  doit respecter. Tu écris ton code dans grille_skeleton.cpp.
// =====================================================================

#include <vector>
#include <cstddef>   // std::size_t

// Une grille est un vecteur de lignes, chaque ligne étant un vecteur
// d'entiers. C'est donc un « vecteur de vecteurs ».
using Grid = std::vector<std::vector<int>>;

// Construit une grille de `rows` lignes et `cols` colonnes, dont toutes
// les cases valent `fill`.
Grid make_grid(std::size_t rows, std::size_t cols, int fill);

// Somme de toutes les cases de la grille.
int grid_sum(const Grid& g);

// Renvoie la transposée de `g` : la case (i, j) de la transposée vaut la
// case (j, i) de `g`. On suppose `g` rectangulaire (toutes les lignes de
// même longueur).
Grid transpose(const Grid& g);
