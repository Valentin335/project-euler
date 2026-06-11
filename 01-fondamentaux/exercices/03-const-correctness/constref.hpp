#pragma once
// Signatures imposées de l'exercice 03. NE PAS MODIFIER ce fichier.

#include <string>
#include <cstddef>

std::size_t length(const std::string& s);  // taille, sans copie
char first_char(const std::string& s);      // 1er caractère ; throw std::invalid_argument si s est vide
void append_excl(std::string& s);           // ajoute " !" à la fin de s, en place
