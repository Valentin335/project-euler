#pragma once
// Signatures imposées de l'exercice 11. NE PAS MODIFIER ce fichier.

#include <string>
#include <vector>
#include <stdexcept>

// Convertit la chaine entiere s en long long.
// Lance std::invalid_argument si s n'est PAS un entier complet valide
// (ex : "12a", "", "  ").
long long parse_int(const std::string& s);

// Decoupe line en entiers separes par des espaces (espaces multiples ignores).
// "" renvoie un vecteur vide.
std::vector<long long> parse_ints(const std::string& line);
