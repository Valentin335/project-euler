// =====================================================================
//  geometry_test.cpp — Tests fournis (NE PAS MODIFIER)
//
//  Compile-le avec ton geometry_skeleton.cpp pour vérifier ta solution.
//  Tant que les corps sont des bouchons, des tests échouent : c'est
//  normal. Ton but est de tous les faire passer.
// =====================================================================

#include "check.hpp"
#include "geometry.hpp"

#include <stdexcept>

// Compare deux double à une petite tolérance près (les calculs en
// virgule flottante ne tombent presque jamais « pile » sur la valeur).
static bool approx(double a, double b)
{
    double diff = a - b;
    if (diff < 0.0) {
        diff = -diff;
    }
    return diff < 1e-6;
}

int main()
{
    // rectangle_area : largeur fois hauteur.
    CHECK(approx(geom::rectangle_area(3.0, 4.0), 12.0));

    // circle_area : pi fois r au carré.
    CHECK(approx(geom::circle_area(1.0), 3.14159265));
    CHECK(approx(geom::circle_area(0.0), 0.0));

    // circle_area doit refuser un rayon négatif.
    CHECK_THROWS(geom::circle_area(-1.0), std::invalid_argument);

    // distance : un classique triangle 3-4-5.
    CHECK(approx(geom::distance(0.0, 0.0, 3.0, 4.0), 5.0));

    return check::report();
}
