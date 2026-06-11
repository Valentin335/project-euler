// Tests de l'exercice 02b « Valeur ou référence » (fournis). Ne pas modifier.
// Compile avec ton valref_skeleton.cpp (voir le bloc « Compiler & tester »
// de l'énoncé).
#include "check.hpp"
#include "valref.hpp"
#include <vector>

int main() {
    // Passage PAR COPIE : la variable de l'appelant ne doit PAS bouger.
    int a = 5;
    double_par_copie(a);
    CHECK_EQ(a, 5);  // inchangé : double_par_copie n'a touché qu'une copie

    // Passage PAR RÉFÉRENCE : la variable de l'appelant doit être doublée.
    int b = 5;
    double_par_reference(b);
    CHECK_EQ(b, 10);  // doublé : la référence a modifié l'original

    // Référence sur un vector : on modifie chaque élément en place.
    std::vector<int> v{1, 2, 3};
    ajoute_a_tous(v, 10);
    CHECK(v == (std::vector<int>{11, 12, 13}));

    // Cas particulier : un vector vide doit rester vide, sans planter.
    std::vector<int> w{};
    ajoute_a_tous(w, 5);
    CHECK(w == (std::vector<int>{}));

    return check::report();
}
