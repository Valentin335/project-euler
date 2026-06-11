#pragma once
// Signatures imposées de l'exercice 03b. NE PAS MODIFIER ce fichier.

#include <vector>
#include <string>
#include <cstddef>

int premier_element(const std::vector<int>& v);  // renvoie v[0] ; throw std::out_of_range si v est vide
void incremente_premier(std::vector<int>& v);     // ajoute 1 au premier élément, en place ; throw std::out_of_range si vide
std::size_t taille(const std::string& s);         // longueur de s (illustre std::size_t et const&)
