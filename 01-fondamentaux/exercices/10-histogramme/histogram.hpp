#pragma once
// =====================================================================
//  histogram.hpp — Signatures imposées de l'exercice « Comptage &
//  histogramme ».
//
//  NE PAS MODIFIER ce fichier : il décrit le contrat que ta solution
//  doit respecter. Tu écris ton code dans histogram_skeleton.cpp.
// =====================================================================

#include <string>
#include <vector>
#include <cstddef>   // std::size_t

// Compte le nombre d'occurrences du caractère c dans la chaine s.
// Sur une chaine vide, le résultat vaut 0.
int count_char(const std::string& s, char c);

// Construit l'histogramme des lettres de l'alphabet présentes dans s.
// Le vecteur renvoyé a toujours une taille de 26 :
//   indice 0 = 'a', indice 1 = 'b', ..., indice 25 = 'z'.
// La casse est ignorée ('A' compte comme 'a') et tout caractere qui
// n'est pas une lettre de l'alphabet est ignore.
std::vector<int> char_histogram(const std::string& s);
