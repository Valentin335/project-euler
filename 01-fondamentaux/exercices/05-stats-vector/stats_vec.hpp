#pragma once
// =====================================================================
//  stats_vec.hpp — Signatures imposées de l'exercice « Statistiques
//  sur vector ».
//
//  NE PAS MODIFIER ce fichier : il décrit le contrat que ta solution
//  doit respecter. Tu écris ton code dans stats_vec_skeleton.cpp.
// =====================================================================

#include <vector>

// Somme de tous les éléments du vecteur.
// Sur un vecteur vide, la somme vaut 0.
int sum(const std::vector<int>& v);

// Moyenne arithmétique des éléments du vecteur.
// Lève std::invalid_argument si v est vide (pas de moyenne définie).
double mean(const std::vector<int>& v);

// Plus grande valeur contenue dans le vecteur.
// Lève std::invalid_argument si v est vide (pas de maximum défini).
int max_value(const std::vector<int>& v);
