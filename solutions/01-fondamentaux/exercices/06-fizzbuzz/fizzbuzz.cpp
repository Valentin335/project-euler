#include "fizzbuzz.hpp"

std::string fizzbuzz_term(int n) {
    // Tester 15 avant 3 et 5, sinon FizzBuzz n'arrive jamais.
    if (n % 15 == 0) return "FizzBuzz";
    if (n % 3 == 0) return "Fizz";
    if (n % 5 == 0) return "Buzz";
    return std::to_string(n);
}

std::vector<std::string> fizzbuzz_range(int from, int to) {
    // Réutilise fizzbuzz_term sur l'intervalle inclusif.
    std::vector<std::string> termes;
    for (int n = from; n <= to; ++n) {
        termes.push_back(fizzbuzz_term(n));
    }
    return termes;
}
