#pragma once
// ===========================================================================
// dureevie.hpp — signatures imposées de l'exercice « Portée et somme par
// référence ».
//
// NE PAS MODIFIER ce fichier.
//
// Tu n'écris RIEN ici : tu remplis seulement dureevie_skeleton.cpp.
// Ce header décrit le CONTRAT (les prototypes) que ton code doit respecter.
// ===========================================================================

#include <vector>

// Ajoute la somme des éléments de `source` à `total`.
// `total` est passé PAR RÉFÉRENCE (int&) : c'est un accumulateur. La fonction
// écrit directement dans la variable de l'appelant, sans rien renvoyer.
void accumule(const std::vector<int>& source, int& total);

// Renvoie le plus grand élément de `v`.
// Lève std::out_of_range si `v` est vide (pas de maximum possible).
int max_local(const std::vector<int>& v);

// Renvoie le nombre d'éléments x de `v` tels que bas <= x <= haut (bornes
// incluses).
int compte_dans_intervalle(const std::vector<int>& v, int bas, int haut);
