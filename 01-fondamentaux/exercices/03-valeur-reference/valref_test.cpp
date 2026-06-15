#include "check.hpp"

#include "valref.hpp"

int main() {
    int a = 5;
    double_par_copie(a);
    CHECK_EQ(a, 5);   // copie : aucun effet

    int b = 5;
    double_par_reference(b);
    CHECK_EQ(b, 10);  // référence : doublé

    std::vector<int> v{1, 2, 3};
    ajoute_a_tous(v, 10);
    CHECK(v == (std::vector<int>{11, 12, 13}));

    return check::report();
}
