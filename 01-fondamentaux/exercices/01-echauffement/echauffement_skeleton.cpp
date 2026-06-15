#include "echauffement.hpp"

int square(int x) {
    /* x → x*x */
    return x*x;
}

long long sum_to(int n) {
    /* n → 1+2+...+n (en 64 bits) */
    return   (static_cast<long long> (n) * (n+1)) /2 ;
}

bool is_even(int x) {
    /* x → vrai si pair */
    return (x%2==0);
}

