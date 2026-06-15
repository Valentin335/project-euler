#include "check.hpp"

#include "strtools.hpp"

int main() {
    CHECK_EQ(to_upper("aBc"), std::string("ABC"));

    CHECK_EQ(trim("  hi  "), std::string("hi"));
    CHECK_EQ(trim("x"), std::string("x"));
    CHECK_EQ(trim("   "), std::string(""));

    CHECK(starts_with("hello", "he"));
    CHECK(!starts_with("hello", "lo"));
    CHECK(starts_with("hi", ""));

    return check::report();
}
