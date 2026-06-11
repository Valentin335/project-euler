// Tests de l'exercice 12 (fournis). Ne pas modifier.
// Compile avec ton optionnel_skeleton.cpp (voir COMPILER.md du chapitre).
#include "check.hpp"
#include "optionnel.hpp"

#include <optional>
#include <vector>
#include <cstddef>

int main() {
    auto i = index_of({10, 20, 30}, 20);
    CHECK(i.has_value());
    CHECK_EQ(i.value(), std::size_t{1});

    auto j = index_of({1, 2}, 9);
    CHECK(!j.has_value());

    auto d = safe_divide(10, 2);
    CHECK(d.has_value());
    CHECK_EQ(d.value(), 5);

    auto z = safe_divide(1, 0);
    CHECK(!z.has_value());

    return check::report();
}
