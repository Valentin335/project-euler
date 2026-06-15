#pragma once
// NE PAS MODIFIER — signatures imposées.
#include <vector>

int somme(const std::vector<int>& v);          // v -> somme des éléments (0 si vide)
void mettre_au_carre(std::vector<int>& v);      // remplace chaque élément par son carré, en place
int compte_pairs(const std::vector<int>& v);    // v -> nombre d'éléments pairs
int max_value(const std::vector<int>& v);       // v -> plus grand élément ; throw std::invalid_argument si vide
