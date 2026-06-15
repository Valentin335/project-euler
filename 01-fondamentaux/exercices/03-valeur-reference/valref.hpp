#pragma once
// Signatures imposées — NE PAS MODIFIER.
#include <vector>

void double_par_copie(int x);                        // x reçu par copie → aucun effet dehors
void double_par_reference(int& x);                   // x reçu par référence → double la variable de l'appelant
void ajoute_a_tous(std::vector<int>& v, int delta);  // v par référence → +delta à chaque élément, en place
