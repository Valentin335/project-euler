#pragma once
// NE PAS MODIFIER — signatures imposées.

#include <string>
#include <vector>

// "a b c" -> {"a", "b", "c"} ; mots séparés par espaces, espaces
// multiples avalés (pas de champ vide) ; "" ou "   " -> {}.
std::vector<std::string> tokenize(const std::string& line);
