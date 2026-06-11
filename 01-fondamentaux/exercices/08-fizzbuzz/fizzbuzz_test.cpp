// Tests de l'exercice 08 (fournis). Ne pas modifier.
// Compile avec ton fizzbuzz_skeleton.cpp (voir COMPILER.md du chapitre).
#include "check.hpp"
#include "fizzbuzz.hpp"

#include <string>
#include <vector>

int main() {
    CHECK_EQ(fizzbuzz_term(3), std::string("Fizz"));
    CHECK_EQ(fizzbuzz_term(5), std::string("Buzz"));
    CHECK_EQ(fizzbuzz_term(15), std::string("FizzBuzz"));
    CHECK_EQ(fizzbuzz_term(7), std::string("7"));
    CHECK_EQ(fizzbuzz_term(1), std::string("1"));

    CHECK_EQ(fizzbuzz_range(1, 5),
             (std::vector<std::string>{"1", "2", "Fizz", "4", "Buzz"}));

    // --- Cas limites ajoutes ---
    // 30 est multiple de 15 : "FizzBuzz" (et non "Fizz" si l'ordre des if est bon).
    CHECK_EQ(fizzbuzz_term(30), std::string("FizzBuzz"));
    // 9 est multiple de 3 seul.
    CHECK_EQ(fizzbuzz_term(9), std::string("Fizz"));
    // 10 est multiple de 5 seul.
    CHECK_EQ(fizzbuzz_term(10), std::string("Buzz"));
    // 0 est multiple de 3 et de 5 (0 % 3 == 0 et 0 % 5 == 0) : "FizzBuzz".
    CHECK_EQ(fizzbuzz_term(0), std::string("FizzBuzz"));

    // Plage reduite a un seul element : from == to.
    CHECK_EQ(fizzbuzz_range(3, 3),
             (std::vector<std::string>{"Fizz"}));
    // Plage encadrant un multiple de 15 : 14, 15 (FizzBuzz), 16.
    CHECK_EQ(fizzbuzz_range(14, 16),
             (std::vector<std::string>{"14", "FizzBuzz", "16"}));
    // Plage avec un negatif : -1 reste "-1", 0 est "FizzBuzz", 1 reste "1".
    CHECK_EQ(fizzbuzz_range(-1, 1),
             (std::vector<std::string>{"-1", "FizzBuzz", "1"}));

    return check::report();
}
