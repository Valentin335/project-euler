#include "moyenne.hpp"

#include <algorithm>
#include <numeric>

std::optional<double> moyenne(const std::vector<double>& v) {
    if (v.empty()) return std::nullopt;  // pas de moyenne sur du vide
    const double somme = std::accumulate(v.begin(), v.end(), 0.0);
    return somme / static_cast<double>(v.size());
}

std::optional<double> mediane(std::vector<double> v) {
    if (v.empty()) return std::nullopt;
    std::sort(v.begin(), v.end());
    const std::size_t n = v.size();
    if (n % 2 == 1) {
        return v[n / 2];  // taille impaire : l'élément central
    }
    return (v[n / 2 - 1] + v[n / 2]) / 2.0;  // taille paire : moyenne des deux centraux
}
