#pragma once
// NE PAS MODIFIER : signatures imposées.
#include <string>
#include <cstddef>

std::size_t length(const std::string& s);  // s -> taille de s, sans copie
char first_char(const std::string& s);      // s -> 1er char ; throw std::invalid_argument si s vide
void append_excl(std::string& s);           // s -> s avec " !" ajouté en place
