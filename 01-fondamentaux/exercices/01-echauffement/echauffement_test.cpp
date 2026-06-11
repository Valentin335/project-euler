// Tests de l'exercice 01 (fournis). Ne pas modifier.
// Compile avec ton echauffement_skeleton.cpp (voir COMPILER.md du chapitre).
#include "check.hpp"
#include "echauffement.hpp"

int main() {
    CHECK_EQ(square(5), 25);
    CHECK_EQ(square(-3), 9);
    CHECK_EQ(square(0), 0);

    CHECK_EQ(sum_to(0), 0LL);
    CHECK_EQ(sum_to(1), 1LL);
    CHECK_EQ(sum_to(100), 5050LL);
    CHECK_EQ(sum_to(100000), 5000050000LL);

    CHECK(is_even(0));
    CHECK(!is_even(7));
    CHECK(is_even(-4));

    return check::report();
}
