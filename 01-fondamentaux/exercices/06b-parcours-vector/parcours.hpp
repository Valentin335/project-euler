#pragma once
// =====================================================================
//  parcours.hpp — Signatures imposées de l'exercice « Parcourir un
//  vector (range-for) ».
//
//  NE PAS MODIFIER ce fichier : il décrit le contrat que ta solution
//  doit respecter. Tu écris ton code dans parcours_skeleton.cpp.
// =====================================================================

#include <vector>

// Somme de tous les éléments du vecteur.
// Parcours en LECTURE : for (const auto& x : v).
// Sur un vecteur vide, la somme vaut 0.
int somme(const std::vector<int>& v);

// Remplace chaque élément du vecteur par son carré, EN PLACE.
// Parcours en MODIFICATION : for (auto& x : v) x = ... ;
// Ne renvoie rien : c'est le vecteur reçu qui est modifié.
void mettre_au_carre(std::vector<int>& v);

// Nombre d'éléments pairs contenus dans le vecteur.
// Parcours en LECTURE : for (const auto& x : v).
// Sur un vecteur vide, le compte vaut 0.
int compte_pairs(const std::vector<int>& v);
