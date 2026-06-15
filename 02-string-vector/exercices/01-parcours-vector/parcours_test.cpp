#include "check.hpp"
#include "parcours.hpp"

#include <stdexcept>
#include <vector>

int main() {
    CHECK_EQ(somme({1, 2, 3, 4}), 10);
    CHECK_EQ(somme({}), 0);

    std::vector<int> v{1, 2, 3};
    mettre_au_carre(v);
    CHECK_EQ(v, (std::vector<int>{1, 4, 9}));

    CHECK_EQ(compte_pairs({1, 2, 3, 4}), 2);

    CHECK_EQ(max_value({3, -1, 2}), 3);
    CHECK_THROWS(max_value({}), std::invalid_argument);

    return check::report();
}
