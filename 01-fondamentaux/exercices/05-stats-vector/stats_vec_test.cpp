// =====================================================================
//  stats_vec_test.cpp — Tests fournis (NE PAS MODIFIER)
//
//  Compile-le avec ton stats_vec_skeleton.cpp pour vérifier ta
//  solution. Tant que les corps sont des bouchons, des tests échouent :
//  c'est normal. Ton but est de tous les faire passer.
// =====================================================================

#include "check.hpp"
#include "stats_vec.hpp"

#include <vector>
#include <stdexcept>

// Compare deux double à une petite tolérance près (les calculs en
// virgule flottante ne tombent presque jamais « pile » sur la valeur).
static bool approx(double a, double b)
{
    double diff = a - b;
    if (diff < 0.0) {
        diff = -diff;
    }
    return diff < 1e-9;
}

int main()
{
    // --- sum ---------------------------------------------------------
    CHECK_EQ(sum(std::vector<int>{1, 2, 3, 4}), 10);
    CHECK_EQ(sum(std::vector<int>{}), 0);
    CHECK_EQ(sum(std::vector<int>{-5, 5}), 0);
    // Cas limite : un seul élément, la somme est cet élément lui-même.
    CHECK_EQ(sum(std::vector<int>{7}), 7);
    // Cas limite : des doublons doivent bien être comptés autant de fois
    // qu'ils apparaissent (3 + 3 + 3 = 9).
    CHECK_EQ(sum(std::vector<int>{3, 3, 3}), 9);

    // --- mean --------------------------------------------------------
    CHECK(approx(mean(std::vector<int>{2, 4}), 3.0));
    CHECK_THROWS(mean(std::vector<int>{}), std::invalid_argument);
    // Cas limite : un seul élément, la moyenne vaut cet élément.
    CHECK(approx(mean(std::vector<int>{5}), 5.0));
    // Cas limite : avec des doublons, moyenne de {3, 3, 3} = 9 / 3 = 3.0.
    CHECK(approx(mean(std::vector<int>{3, 3, 3}), 3.0));
    // Cas piège du type : 1 + 2 + 3 + 4 = 10, 10 / 4 = 2.5. Une division
    // entière donnerait 2 au lieu de 2.5, ce test débusque cette erreur.
    CHECK(approx(mean(std::vector<int>{1, 2, 3, 4}), 2.5));

    // --- max_value ---------------------------------------------------
    CHECK_EQ(max_value(std::vector<int>{-5, -2, -9}), -2);
    CHECK_EQ(max_value(std::vector<int>{3, 1, 2}), 3);
    CHECK_THROWS(max_value(std::vector<int>{}), std::invalid_argument);
    // Cas limite : le maximum apparaît en doublon, le résultat reste 4.
    CHECK_EQ(max_value(std::vector<int>{4, 4, 2}), 4);
    // Cas limite : un seul élément, le maximum est cet élément.
    CHECK_EQ(max_value(std::vector<int>{9}), 9);
    // Cas limite : tout négatif, le maximum est le « moins négatif ». Une
    // initialisation naïve à 0 renverrait 0 à tort ici.
    CHECK_EQ(max_value(std::vector<int>{-10, -3, -7}), -3);

    return check::report();
}
