// ===========================================================================
// dureevie_test.cpp — batterie de tests de l'exercice « Portée et somme par
// référence ».
//
// Tu n'as PAS à modifier ce fichier. Compile-le avec ton squelette et lance
// l'exécutable : tant que des tests échouent, continue de travailler dans
// dureevie_skeleton.cpp.
// ===========================================================================

#include "check.hpp"
#include "dureevie.hpp"

#include <stdexcept>
#include <vector>

int main() {
    // --- accumule : un appel ajoute la somme à l'accumulateur ---------------
    int t = 100;
    accumule({1, 2, 3}, t);
    CHECK_EQ(t, 106);  // 100 + (1 + 2 + 3)

    // --- accumule : vecteur vide -> total inchangé --------------------------
    int t2 = 0;
    accumule({}, t2);
    CHECK_EQ(t2, 0);

    // --- accumule : deux appels successifs s'accumulent ---------------------
    int t3 = 5;
    accumule({10}, t3);
    accumule({20}, t3);
    CHECK_EQ(t3, 35);  // 5 + 10 + 20

    // --- max_local : plus grand élément -------------------------------------
    CHECK_EQ(max_local({3, 7, 2}), 7);
    CHECK_EQ(max_local({-5, -1, -9}), -1);
    CHECK_THROWS(max_local(std::vector<int>{}), std::out_of_range);

    // --- compte_dans_intervalle : bornes incluses ---------------------------
    CHECK_EQ(compte_dans_intervalle({1, 5, 10, 15}, 5, 12), 2);   // 5 et 10
    CHECK_EQ(compte_dans_intervalle({1, 2, 3}, 10, 20), 0);       // aucun

    return check::report();
}
