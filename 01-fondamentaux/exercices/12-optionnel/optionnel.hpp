#pragma once
// Signatures imposées de l'exercice 12. NE PAS MODIFIER ce fichier.

#include <optional>
#include <vector>
#include <cstddef>

// Renvoie la position du premier element egal a target, ou std::nullopt
// si target n'apparait pas dans v.
std::optional<std::size_t> index_of(const std::vector<int>& v, int target);

// Renvoie a / b, ou std::nullopt si b == 0 (division impossible).
std::optional<int> safe_divide(int a, int b);
