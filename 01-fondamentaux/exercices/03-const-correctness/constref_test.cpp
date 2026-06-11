// Tests de l'exercice 03 (fournis). Ne pas modifier.
// Compile avec ton constref_skeleton.cpp (voir enonce.md).
#include "check.hpp"
#include "constref.hpp"

#include <stdexcept>
#include <string>

int main() {
    CHECK_EQ(length("hello"), std::size_t{5});
    CHECK_EQ(length(""), std::size_t{0});

    CHECK_EQ(first_char("abc"), 'a');
    CHECK_THROWS(first_char(std::string("")), std::invalid_argument);

    std::string s = "ok";
    append_excl(s);
    CHECK_EQ(s, std::string("ok !"));

    return check::report();
}
