#include "optionnel.hpp"

std::optional<std::size_t> index_of(const std::vector<int>& v, int target) {
    // boucle indexée : on renvoie l'index dès qu'on trouve
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (v[i] == target) return i;
    }
    return std::nullopt;  // absent
}

std::optional<int> safe_divide(int a, int b) {
    if (b == 0) return std::nullopt;  // division impossible
    return a / b;
}
