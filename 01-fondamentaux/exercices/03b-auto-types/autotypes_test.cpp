// Tests de l'exercice 03b (fournis). Ne pas modifier.
// Compile avec ton autotypes_skeleton.cpp (voir enonce.md).
#include "check.hpp"
#include "autotypes.hpp"

#include <vector>
#include <string>
#include <stdexcept>
#include <cstddef>

int main() {
    // premier_element : lecture (copie) du premier élément.
    CHECK_EQ(premier_element(std::vector<int>{7, 8, 9}), 7);
    CHECK_THROWS(premier_element(std::vector<int>{}), std::out_of_range);

    // incremente_premier : modification EN PLACE via une référence.
    std::vector<int> v{4, 5};
    incremente_premier(v);
    CHECK(v == (std::vector<int>{5, 5}));

    std::vector<int> e{};
    CHECK_THROWS(incremente_premier(e), std::out_of_range);

    // taille : longueur d'une chaîne reçue en const&.
    CHECK_EQ(taille("bonjour"), std::size_t{7});
    CHECK_EQ(taille(""), std::size_t{0});

    return check::report();
}
