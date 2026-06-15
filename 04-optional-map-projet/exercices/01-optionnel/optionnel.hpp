#pragma once
// NE PAS MODIFIER
#include <optional>
#include <vector>
#include <cstddef>

// v, cible -> index de la 1re occurrence, ou nullopt si absente
std::optional<std::size_t> index_of(const std::vector<int>& v, int target);

// a, b -> a/b, ou nullopt si b == 0
std::optional<int> safe_divide(int a, int b);
