#include "check.hpp"
#include "parse_int.hpp"

int main() {
    // parse_int
    CHECK_EQ(parse_int("42"), 42LL);
    CHECK_THROWS(parse_int("12a"), std::invalid_argument);
    CHECK_THROWS(parse_int(""), std::invalid_argument);

    // parse_ints
    CHECK(parse_ints("1 2 3") == (std::vector<long long>{1, 2, 3}));
    CHECK(parse_ints("1   2") == (std::vector<long long>{1, 2}));
    CHECK(parse_ints("") == std::vector<long long>{});

    return check::report();
}
