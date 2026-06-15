#include "optionnel.hpp"

std::optional<std::size_t> index_of(const std::vector<int>& v, int target) {
    /* v, cible -> index ou nullopt */
    (void)v;
    (void)target;
    return std::nullopt;
}

std::optional<int> safe_divide(int a, int b) {
    /* a, b -> a/b ou nullopt si b==0 */
    (void)a;
    (void)b;
    return std::nullopt;
}
