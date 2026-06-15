#include "check.hpp"
#include "moyenne.hpp"

#include <cmath>

// Compare deux double à une tolérance près (les flottants ne se comparent pas
// avec ==). On déballe l'optional pour vérifier d'abord qu'il a une valeur.
static bool proche(const std::optional<double>& got, double attendu) {
    return got.has_value() && std::abs(*got - attendu) < 1e-9;
}

int main() {
    CHECK(proche(moyenne({2, 4, 6}), 4.0));
    CHECK(moyenne({}) == std::nullopt);

    CHECK(proche(mediane({3, 1, 2}), 2.0));
    CHECK(proche(mediane({4, 1, 3, 2}), 2.5));
    CHECK(mediane({}) == std::nullopt);

    return check::report();
}
