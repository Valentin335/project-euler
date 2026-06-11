// =====================================================================
// rotation_test.cpp — tests de l'exercice "Échange & rotation".
// Lance : voir la commande g++ dans enonce.md.
// =====================================================================

#include "check.hpp"
#include "rotation.hpp"

int main() {
    // -- swap_ints : (1, 2) -> (2, 1) -------------------------------
    int a = 1;
    int b = 2;
    swap_ints(a, b);
    CHECK_EQ(a, 2);
    CHECK_EQ(b, 1);

    // -- rotate_left : (1, 2, 3) -> (2, 3, 1) -----------------------
    int x = 1;
    int y = 2;
    int z = 3;
    rotate_left(x, y, z);
    CHECK_EQ(x, 2);
    CHECK_EQ(y, 3);
    CHECK_EQ(z, 1);

    // -- Idempotence : 3 rotations gauche reviennent au départ ------
    int p = 1;
    int q = 2;
    int r = 3;
    rotate_left(p, q, r);
    rotate_left(p, q, r);
    rotate_left(p, q, r);
    CHECK_EQ(p, 1);
    CHECK_EQ(q, 2);
    CHECK_EQ(r, 3);

    return check::report();
}
