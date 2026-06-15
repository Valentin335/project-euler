#include "check.hpp"
#include "fizzbuzz.hpp"

int main() {
    CHECK_EQ(fizzbuzz_term(3), std::string("Fizz"));
    CHECK_EQ(fizzbuzz_term(5), std::string("Buzz"));
    CHECK_EQ(fizzbuzz_term(15), std::string("FizzBuzz"));
    CHECK_EQ(fizzbuzz_term(7), std::string("7"));

    std::vector<std::string> attendu{"1", "2", "Fizz", "4", "Buzz"};
    CHECK_EQ(fizzbuzz_range(1, 5), attendu);

    return check::report();
}
