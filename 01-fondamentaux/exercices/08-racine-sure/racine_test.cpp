#include "check.hpp"
#include "racine.hpp"
#include <stdexcept>

int main() {
    int o = -42;

    CHECK_EQ(try_sqrt_int(9, o), true);
    CHECK_EQ(o, 3);

    CHECK_EQ(try_sqrt_int(10, o), false);
    CHECK_EQ(try_sqrt_int(-1, o), false);

    CHECK_EQ(checked_sqrt_int(16), 4);
    CHECK_THROWS(checked_sqrt_int(-1), std::domain_error);
    CHECK_THROWS(checked_sqrt_int(10), std::invalid_argument);

    return check::report();
}
