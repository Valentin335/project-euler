#pragma once
// Signatures imposées de l'exercice 02b « Valeur ou référence ».
// NE PAS MODIFIER ce fichier.

#include <vector>

// Reçoit une COPIE de l'entier de l'appelant : modifier x ici ne change
// RIEN chez l'appelant.
void double_par_copie(int x);

// Reçoit une RÉFÉRENCE (un alias) vers l'entier de l'appelant : modifier x
// ici modifie directement la variable de l'appelant.
void double_par_reference(int& x);

// Reçoit une RÉFÉRENCE vers le vector de l'appelant : ajoute delta à CHAQUE
// élément, en place (sans copie du vector).
void ajoute_a_tous(std::vector<int>& v, int delta);
