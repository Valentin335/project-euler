// =====================================================================
//  parcours_test.cpp — Tests fournis (NE PAS MODIFIER)
//
//  Compile-le avec ton parcours_skeleton.cpp pour vérifier ta
//  solution. Tant que les corps sont des bouchons, des tests échouent :
//  c'est normal. Ton but est de tous les faire passer.
// =====================================================================

#include "check.hpp"
#include "parcours.hpp"

#include <vector>

int main()
{
    // --- somme -------------------------------------------------------
    CHECK_EQ(somme(std::vector<int>{1, 2, 3, 4}), 10);
    CHECK_EQ(somme(std::vector<int>{}), 0);
    CHECK_EQ(somme(std::vector<int>{-2, 2}), 0);
    // Cas limite : un seul élément, la somme est cet élément lui-même.
    CHECK_EQ(somme(std::vector<int>{7}), 7);

    // --- mettre_au_carre --------------------------------------------
    // Vérifie la modification EN PLACE : on appelle, puis on compare le
    // vecteur lui-même à ce qu'il devrait contenir.
    std::vector<int> v{1, 2, 3};
    mettre_au_carre(v);
    CHECK(v == (std::vector<int>{1, 4, 9}));

    // Cas limite : un élément négatif, son carré est positif (-3 -> 9).
    std::vector<int> n{-3};
    mettre_au_carre(n);
    CHECK(n == (std::vector<int>{9}));

    // Cas limite : un vecteur vide reste vide (rien à mettre au carré).
    std::vector<int> vide{};
    mettre_au_carre(vide);
    CHECK(vide == (std::vector<int>{}));

    // --- compte_pairs ------------------------------------------------
    CHECK_EQ(compte_pairs(std::vector<int>{1, 2, 3, 4, 5, 6}), 3);
    CHECK_EQ(compte_pairs(std::vector<int>{1, 3, 5}), 0);
    CHECK_EQ(compte_pairs(std::vector<int>{}), 0);
    // Cas limite : les pairs négatifs comptent aussi (-4 et 0 sont pairs).
    CHECK_EQ(compte_pairs(std::vector<int>{-4, 0, 7}), 2);

    return check::report();
}
