#include "echauffement.hpp"

int square(int x) {
    return x * x;
}

long long sum_to(int n) {
    // Formule de Gauss ; static_cast force le calcul en 64 bits (anti-overflow).
    return static_cast<long long>(n) * (n + 1) / 2;
}

bool is_even(int x) {
    return x % 2 == 0;
}
