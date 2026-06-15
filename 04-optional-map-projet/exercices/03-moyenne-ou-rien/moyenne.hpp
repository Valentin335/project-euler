#pragma once
// NE PAS MODIFIER
#include <optional>
#include <vector>

// v -> moyenne arithmétique des éléments, ou nullopt si v est vide
std::optional<double> moyenne(const std::vector<double>& v);

// v (copie, pour pouvoir trier) -> médiane, ou nullopt si v est vide
std::optional<double> mediane(std::vector<double> v);
