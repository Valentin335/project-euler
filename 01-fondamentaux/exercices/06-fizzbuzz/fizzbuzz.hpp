#pragma once
// NE PAS MODIFIER : signatures imposées.
#include <string>
#include <vector>

// n → "Fizz" si div. par 3, "Buzz" si par 5, "FizzBuzz" si par 15, sinon le nombre.
std::string fizzbuzz_term(int n);

// from, to → liste des termes FizzBuzz de from à to inclus.
std::vector<std::string> fizzbuzz_range(int from, int to);
